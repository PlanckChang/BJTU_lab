import re
import matplotlib.pyplot as plt

# 假设你的文件名是data.txt
file_name = 'out2.txt'

# 初始化列表以存储数据
epochs = []
losses = []
train_accs = []
test_accs = []

with open(file_name, 'r') as file:
    for line in file:
        # 匹配到含有loss, train_acc和test_acc的行
        if 'loss' in line and 'train_acc' in line and 'test_acc' in line:
            split_line = re.split(r'[=, ]+', line.strip())

            epoch = int(split_line[split_line.index('epoch') + 1])
            loss = float(split_line[split_line.index('loss') + 1])
            train_acc = float(split_line[split_line.index('train_acc') + 1])
            test_acc = float(split_line[split_line.index('test_acc') + 1])

            epochs.append(epoch)
            losses.append(loss)
            train_accs.append(train_acc)
            test_accs.append(test_acc)

# 使用matplotlib绘制数据
plt.figure()
plt.plot(epochs, losses, label='Loss')
plt.plot(epochs, train_accs, label='Train Accuracy')
plt.plot(epochs, test_accs, label='Test Accuracy')
plt.xlabel('Epochs')
plt.ylabel('Value')
plt.legend()
plt.title('Loss, Train Accuracy, and Test Accuracy vs Epochs')
# plt.show()
plt.savefig("output.svg", farmat='svg')
