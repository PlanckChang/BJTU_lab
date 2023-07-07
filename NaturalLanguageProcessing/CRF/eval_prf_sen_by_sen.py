from sklearn.metrics import precision_score, recall_score, f1_score, accuracy_score
import warnings
warnings.filterwarnings("ignore")


def eval_prf(input_file):
    y_true = []
    y_pred = []
    with open(input_file, encoding="utf-8") as f:
        pre = 0.0
        rec = 0.0
        f1 = 0.0
        acc = 0.0
        num = 0
        for line in f.readlines():
            word = line.strip().split()
            # each sample gain a score

            if len(word) != 3:
                pre += precision_score(y_true, y_pred, average="weighted")
                rec += recall_score(y_true, y_pred, average="weighted")
                f1 += f1_score(y_true, y_pred, average="weighted")
                acc += accuracy_score(y_true, y_pred)
                y_true = []
                y_pred = []
                num += 1
                continue
            # print(word)
            y_true.append(word[-1])
            y_pred.append(word[-2])

    print("Precision: %.2f" % (100 * pre / num))
    print("Recall: %.2f" % (100 * rec / num))
    print("F1: %.2f" % (100 * f1 / num))
    print("Accuracy: %.2f" % (100 * acc / num))


if __name__ == "__main__":
    print("eval train_dataset")
    eval_prf("./data/train_people_daily_eval2.txt")
    print("\n\n")
    print("eval test_dataset")
    eval_prf("./data/test_people_daily_eval2.txt")

