from sklearn.metrics import precision_score, recall_score, f1_score, accuracy_score, classification_report
import warnings
warnings.filterwarnings("ignore")


def eval_prf(input_file):
    y_true = []
    y_pred = []
    with open(input_file, encoding="gbk") as f:

        for line in f.readlines():
            word = line.strip().split()
            # each sample gain a score
            if len(word) == 0:
                continue
            y_true.append(word[-1])
            y_pred.append(word[-2])
    print()
    print("Precision: %.2f" % (100 * precision_score(y_true, y_pred, average="weighted")))
    print("Recall: %.2f" % (100 * recall_score(y_true, y_pred, average="weighted")))
    print("F1: %.2f" % (100 * f1_score(y_true, y_pred, average="weighted")))
    print("Accuracy: %.2f" % (100 * accuracy_score(y_true, y_pred)))


if __name__ == "__main__":
    print("eval train_dataset")
    eval_prf("./seg_with_example_template/train_eval.txt")
    print("\n\n")
    print("eval test_dataset")
    eval_prf("./seg_with_example_template/test_eval.txt")

