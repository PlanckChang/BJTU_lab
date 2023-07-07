import math
from sklearn.metrics import precision_score, accuracy_score, recall_score, f1_score
import json
import warnings
warnings.filterwarnings("ignore")

class HMM:
    def __init__(self, train_file_path, check_point_flag=False):
        self.file_path = train_file_path
        self.pi = {}                    # 初始状态概率分布
        self.A = {}                     # 状态转移概率矩阵
        self.B = {}                     # 观察值概率矩阵
        self.pos = []                   # 所有词性
        self.tag_fre = {}               # 词性出现频率
        self.A_class = {}               # 状态转移平滑处理矩阵 某tag下一个word出现的次数为0 的次数
        self.B_class = {}               # 观察概率平滑处理矩阵

        if check_point_flag:
            self.load_model()
            print("load model done")

    def load_model(self):
        with open("./data/pi.json", "r", encoding='utf-8') as f:
            self.pi = json.load(f)
        with open("./data/A.json", "r", encoding='utf-8') as f:
            self.A = json.load(f)
        with open("./data/B.json", "r", encoding='utf-8') as f:
            self.B = json.load(f)
        with open("./data/pos.json", "r", encoding='utf-8') as f:
            self.pos = json.load(f)
        with open("./data/tag_fre.json", "r", encoding='utf-8') as f:
            self.tag_fre = json.load(f)
        with open("./data/A_class.json", "r", encoding='utf-8') as f:
            self.A_class = json.load(f)
        with open("./data/B_class.json", "r", encoding='utf-8') as f:
            self.B_class = json.load(f)

    def save_model(self):
        with open("./data/pi.json", "w", encoding='utf-8') as f:
            json.dump(self.pi, f)
        with open("./data/A.json", "w", encoding='utf-8') as f:
            json.dump(self.A, f)
        with open("./data/B.json", "w", encoding='utf-8') as f:
            json.dump(self.B, f)
        with open("./data/pos.json", "w", encoding='utf-8') as f:
            json.dump(self.pos, f)
        with open("./data/tag_fre.json", "w", encoding='utf-8') as f:
            json.dump(self.tag_fre, f)
        with open("./data/A_class.json", "w", encoding='utf-8') as f:
            json.dump(self.A_class, f)
        with open("./data/B_class.json", "w", encoding='utf-8') as f:
            json.dump(self.B_class, f)

    def build_hmm(self):
        all_words = set()
        with open(self.file_path, 'r', encoding='utf-8') as f:
            all_sentence = f.readlines()
        line_counts = len(all_sentence)
        for sen in all_sentence:
            sen = sen.rstrip('\n')
            word_count = sen.split()
            for word_with_tag in word_count:
                words = word_with_tag.split('/')
                if len(words) == 2:
                    all_words.add(words[0])
                    if words[1] not in self.pos:
                        self.pos.append(words[1])

        print("first step done")
        print(len(self.pos))

        for tag in self.pos:
            self.pi[tag] = 0
            self.tag_fre[tag] = 0
            self.A[tag] = {}
            self.B[tag] = {}
            for next_tag in self.pos:
                self.A[tag][next_tag] = 0
            for word in all_words:
                self.B[tag][word] = 0

        for sen in all_sentence:
            sen = sen.rstrip('\n')
            if sen == '':
                continue

            tmp_word = sen.split()
            counts = len(tmp_word)
            head_word = tmp_word[0].split('/')
            self.pi[head_word[1]] += 1
            self.tag_fre[head_word[1]] += 1
            self.B[head_word[1]][head_word[0]] += 1
            for i in range(1, counts):
                current_word = tmp_word[i].split('/')
                pre_word = tmp_word[i - 1].split('/')
                if len(current_word) == 2:
                    if current_word[-1] and pre_word[-1]:
                        self.tag_fre[current_word[-1]] += 1
                        self.A[pre_word[-1]][current_word[-1]] += 1
                        self.B[current_word[-1]][current_word[0]] += 1

        print("second step done")

        # 矩阵中零太多，做平滑处理
        for tag in self.pos:
            self.A_class[tag] = 0
            self.B_class[tag] = 0
            if self.pi[tag] == 0:
                self.pi[tag] = 0.5 / line_counts
            else:
                self.pi[tag] = self.pi[tag] * 1.0 / line_counts
            for next_tag in self.pos:
                if self.A[tag][next_tag] == 0:
                    self.A_class[tag] += 1
                    self.A[tag][next_tag] = 0.5
            for word in all_words:
                if self.B[tag][word] == 0:
                    self.B_class[tag] += 1
                    self.B[tag][word] = 0.5
        # 平滑后的概率再进行归一化
        for tag in self.pos:
            for next_tag in self.pos:
                self.A[tag][next_tag] = self.A[tag][next_tag] * 1.0 / (self.tag_fre[tag] + self.A_class[tag])
            #     tag_fre 为 此tag出现的次数，A_class 为 此tag下word的次数为0 的个数，即修改的操作次数。
            for word in all_words:
                self.B[tag][word] = self.B[tag][word] * 1.0 / (self.tag_fre[tag] + self.B_class[tag])

        self.save_model()
        print("save model done")
        print("build done")
        # print("\n\n pi:")
        # print(self.pi)
        # print("\n\n A:")
        # print(self.A)
        # print("\n\n B:")
        # print(self.B)

    def predict_pos_tags(self, test_file_path, truth_file_path, flag="train", mode="seg"):
        print("start predict for " + flag)

        with open(test_file_path, 'r', encoding='utf-8') as f:
            test_sentence = f.readlines()

        with open(truth_file_path, 'r', encoding='utf-8') as f:
            truth_tags = f.readlines()

        with open(f'./data/{flag}_result.txt', 'w', encoding='utf-8') as f:
            total_acc = 0.0
            total_pre = 0.0
            total_recall = 0.0
            total_f1 = 0.0

            for ind in range(len(test_sentence)):
                res = []
                sen = test_sentence[ind]
                sen = sen.rstrip('\n').split()
                if mode == "tag":
                    sen = sen[:-1]
                sen_length = len(sen)
                delta = [{} for i in range(sen_length)]
                psi = [{} for i in range(sen_length)]
                for tag in self.pos:
                    for index in range(sen_length):
                        delta[index][tag] = -1e100
                        psi[index][tag] = ""

                for tag in self.pos:
                    if sen[0] in self.B[tag]:
                        delta[0][tag] = math.log(self.pi[tag] * self.B[tag][sen[0]])
                    else:
                        delta[0][tag] = math.log(self.pi[tag] * 0.5 / (self.B_class[tag] + self.tag_fre[tag]))

                for i in range(1, sen_length):
                    for tag in self.pos:
                        # 未登录词的处理 直接取0.5，同时归一化到平滑后的概率
                        if sen[i] in self.B[tag]:
                            tmp = math.log(self.B[tag][sen[i]])
                        else:
                            tmp = math.log(0.5 / (self.B_class[tag] + self.tag_fre[tag]))
                        for pre_tag in self.pos:
                            if delta[i][tag] < (delta[i - 1][pre_tag] + math.log(self.A[pre_tag][tag]) + tmp):
                                delta[i][tag] = delta[i - 1][pre_tag] + math.log(self.A[pre_tag][tag]) + tmp
                                psi[i][tag] = pre_tag

                max_end = self.pos[0]
                for tag in self.pos:
                    if delta[sen_length - 1][max_end] < delta[sen_length - 1][tag]:
                        max_end = tag

                i = sen_length - 1
                res.append(max_end)
                while i > 0:
                    max_end = psi[i][max_end]
                    res.append(max_end)
                    i -= 1
                res.reverse()

                truth = truth_tags[ind].rstrip("\n").split()
                if mode == "tag":
                    truth = truth[:-1]
                if len(truth) != len(res):
                    print("this sentence has wrong word amount. wrong!")
                    continue

                acc = accuracy_score(truth, res)
                pre = precision_score(truth, res, average='weighted')
                rec = recall_score(truth, res, average='weighted')
                f1 = f1_score(truth, res, average='weighted')


                f.write(f'{ind} expected: ' + ' '.join(truth) + '\n')
                f.write('got: ' + ' '.join(res) + '\n')
                f.write("acc: %f, pre: %f, rec: %f, f1: %f" % (acc, pre, rec, f1) + '\n\n')

                total_acc += acc
                total_pre += pre
                total_recall += rec
                total_f1 += f1

            average_acc = total_acc / len(test_sentence)
            average_pre = total_pre / len(test_sentence)
            average_recall = total_recall / len(test_sentence)
            average_f1 = total_f1 / len(test_sentence)

            print("average acc %f" % average_acc)
            f.write("average acc " + str(average_acc))
            print("average pre %f" % average_pre)
            f.write("average pre " + str(average_pre))
            print("average recall %f" % average_recall)
            f.write("average recall " + str(average_recall))
            print("average f1 %f" % average_f1)
            f.write("average f1 " + str(average_f1))


if __name__ == '__main__':
    hmm = HMM('./tagging/tag_data/train1998people_daily.txt')
    hmm.build_hmm()
    hmm.predict_pos_tags('./tagging/tag_data/train_x.txt', './tagging/tag_data/train_y.txt', flag="train")
    hmm.predict_pos_tags('./tagging/tag_data/test_x.txt', './tagging/tag_data/test_y.txt', flag="test")