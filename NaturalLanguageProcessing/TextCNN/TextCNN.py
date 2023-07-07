import os
import re 
import sys
import torch
import random
from torch import optim
from torch import nn as nn
from torch.nn import functional as F
from torch.utils import data as Data
from torchtext import vocab as Vocab
from sklearn.metrics import accuracy_score

sys.path.append('.')

class TextCNN(nn.Module):
    def __init__(self, vocab_size, embed_size, kernel_sizes, channel_size, dropout) -> None:
        super().__init__()
        self.embed = nn.Embedding(vocab_size, embed_size)
        self.const_embed = nn.Embedding(vocab_size, embed_size)

        self.dropout = nn.Dropout(dropout)

        self.conv_list = nn.ModuleList()
        for channel, kernel in zip(channel_size, kernel_sizes):
            self.conv_list.append(nn.Conv1d(in_channels=2*embed_size, out_channels=channel, kernel_size=kernel))
        
        self.relu = nn.ReLU()
        self.dense = nn.Linear(sum(channel_size), 2)
    
    def forward(self, x):
        embed1 = self.embed(x)
        embed2 = self.const_embed(x)

        embeds = torch.cat((embed1, embed2), dim=-1)

        embeds = embeds.permute(0, 2, 1)

        conv_results = []
        for conv in self.conv_list:
            conv_out = self.relu(conv(embeds))
            pool_out = F.max_pool1d(conv_out, kernel_size=conv_out.shape[2]).squeeze(-1)
            conv_results.append(pool_out)
        
        conv_out = torch.cat(conv_results, dim=1)
        conv_out = self.dropout(conv_out)
        outputs = self.dense(conv_out)
        
        return outputs
    
class Dataset():
    def __init__(self, data_path, embed_size):
        self.data_path = data_path
        self.glove_vocab = Vocab.GloVe(name='6B', dim=embed_size, cache=os.path.join(data_path, 'glove'))
        self.data = self.file_read(data_path)
        self.word2idx, self.idx2word = self.bulid_vocab()
    
    def text_clean(self, text):
        text = text.replace('<br />', '')
        text = text.replace("'s", " is").replace("'m", " am").replace("'re", " are") \
                    .replace("n't", " not").replace("'ll", " will").replace("'ve", " have")
        pattern = '\[\]\{\}\(\)'
        text = re.sub(r"[{}]".format(pattern), "", text.lower())
        text = re.sub(r"\.+", ' . ', text)
        text = re.sub(r",", ' , ', text)
        text = re.sub(r"!", " ! ", text)
        text = re.sub(r"\"", " \" ", text)
        text = re.sub(r"\?", " ? ", text)
        # #
        text = re.sub(r"\s{2,}", ' ', text)
        return text.strip()
    
    def file_read(self, data_path):
        res = {}
        for split in ['train', 'valid', 'test']:
            if split == 'valid':
                continue
            data = []   
            for label in ['pos', 'neg']:
                data_dir = os.path.join(data_path, split, label)
                for file in os.listdir(data_dir):
                    with open(os.path.join(data_dir, file)) as fin:
                        review = fin.read().strip()
                        cleaned_review = self.text_clean(review)
                        lab = 1 if label == 'pos' else 0
                        data.append((cleaned_review, lab))
            
            random.shuffle(data)
            res[split] = data
        return res
    
    def get_glove_vectors(self, ):
        return self.glove_vocab.vectors
    
    def get_vocab_size(self):
        return len(self.word2idx)
    
    def bulid_vocab(self):
        words = self.glove_vocab.itos
        word2idx = {word: idx for idx, word in enumerate(words)}
        idx2word = {idx: word for idx, word in enumerate(words)}
        return word2idx, idx2word
    
    def get_dataloader(self, split, batch_size, max_len):
        word2idx = self.word2idx
        unk = word2idx['unk']
        pad = word2idx['pad']   
        review_list, label_list = [], []
        data = self.data[split]

        for item in data:
            review, label = item[0], item[1]
            review = [word2idx[word] if word in word2idx else unk for word in review.split(' ')]
            review = review[:max_len] if len(review) > max_len else review +[pad]*(max_len-len(review))

            review_list.append(review)
            label_list.append(label)

        review_list = torch.tensor(review_list)
        label_list  = torch.tensor(label_list)

        split_dataset = Data.TensorDataset(review_list, label_list)
        dataloader = Data.DataLoader(split_dataset, batch_size=batch_size, shuffle=True if split != 'test' else False, num_workers=4)
        return dataloader


def train():
    dataset = Dataset(data_path, embed_size)
    train_loader, valid_loader = dataset.get_dataloader('train', batch_size, max_len), dataset.get_dataloader('test', batch_size, max_len)

    glove_vocab_vectors = dataset.get_glove_vectors()
    textcnn = TextCNN(dataset.get_vocab_size(), embed_size, kernel_sizes, channel_sizes, dropout)
    textcnn.embed.weight.data.copy_(glove_vocab_vectors)
    textcnn.const_embed.weight.data.copy_(glove_vocab_vectors)
    textcnn.const_embed.requires_grad_(False)
    # textcnn.load_state_dict(torch.load("./checkpoints/checkpoint_epoch_9.pth"))
    textcnn.to(device)

    optimizer = optim.Adam(filter(lambda p: p.requires_grad, textcnn.parameters()),
                           lr=lr,
                           weight_decay=weigth_decay)
    loss = nn.CrossEntropyLoss()
    
    def valid(model):
        model.eval()
        valid_acc, n = 0.0, 0
        with torch.no_grad():
            for x, y in valid_loader:
                x = x.to(device)
                y = y.to(device)
                output = model(x)

                y = y.data.cpu().numpy()
                output = output.argmax(dim=1).data.cpu().numpy()
                valid_acc += accuracy_score(y, output)
                n += 1
        return valid_acc / n
    
    best_acc = 0
    for epoch in range(epochs):
        textcnn.train()
        train_loss, train_acc, n = 0.0, 0.0, 0
        for x, y in train_loader:
            x, y = x.to(device), y.to(device)
            # print(x)
            output = textcnn(x)
            l = loss(output, y).sum()
            
            optimizer.zero_grad()
            l.backward()
            optimizer.step()
            
            # train_loss += l / y.shape[0]
            train_loss += l
            train_acc += accuracy_score(y.data.cpu().numpy(), output.argmax(dim=1).data.cpu().numpy())
            n += 1
            if n > 0 and n % 10 == 0:
                print("epoch %d, step %d, train_loss: %.2f" % (epoch, n, l))

        valid_acc = valid(textcnn)
        print('epoch = %d, loss = %.4f, train_acc = %.4f, test_acc = %.4f'
              % (epoch + 1, train_loss / n, train_acc / n, valid_acc))
        if not os.path.exists('./checkpoints'):
            os.makedirs('./checkpoints')
        torch.save(textcnn.state_dict(), './checkpoints/checkpoint_epoch_%d.pth' % (epoch))
        if valid_acc >= best_acc:
            best_acc = valid_acc
            torch.save(textcnn.state_dict(), './checkpoints/checkpoint_%.2f.pth' % (valid_acc * 100))
            print('model acc: %.2f%%, save...' % (valid_acc * 100))


if __name__ == '__main__':
    batch_size = 512
    max_len = 512
    embed_size = 300 # embed_size 与 glove 的 dim 相同
    kernel_sizes = [2, 3, 4, 5] # 参考: A Sensitivity Analysis of (and Practitioners’ Guide to) Convolutional Neural Networks for Sentence Classification
    channel_sizes = [100, 100, 100, 100]
    dropout = 0.6
    epochs = 50
    lr = 3e-4 # batch_size 越大, lr 越大
    weigth_decay = 1e-7
    device = torch.device("cuda:2" if torch.cuda.is_available() else "cpu")

    data_path = '/data1/zhangzhiwei/data/aclImdb'
    
    train()
    # test()
            