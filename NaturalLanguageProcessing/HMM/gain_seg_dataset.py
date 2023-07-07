def add_seg(input_file, output_file):
    with open(input_file,"r", encoding="utf-8") as f1, open(output_file, "w", encoding="utf-8") as f2:
        for line in f1.readlines():
            if line == "\n":
                continue
            for word in line.strip().split():
                if len(word) == 1:
                    f2.write(word + "/S ")
                elif len(word) == 2:
                    f2.write(word[0] + "/B " + word[1] + "/E ")
                else:
                    f2.write(word[0] + "/B ")
                    for w in word[1:-1]:
                        f2.write(w + "/M ")
                    f2.write(word[-1] + "/E ")
            f2.write("\n")


def split_into_x_y(input_file, output_file1, output_file2):
    with open(input_file, "r", encoding="utf-8") as f1, open(output_file1, "w", encoding="utf-8") as f2, open(output_file2, "w", encoding="utf-8") as f3:
        for line in f1.readlines():
            if line == "\n":
                continue
            for word in line.strip().split():
                word, tag = word.split("/")
                f2.write(word + " ")
                f3.write(tag + " ")
            f2.write("\n")
            f3.write("\n")


if __name__ == "__main__":
    add_seg("pku_training.utf8", "pku_training_seg.utf8")
    add_seg("pku_test_gold.utf8", "pku_test_seg.utf8")

    split_into_x_y("pku_training_seg.utf8", "pku_training_x.utf8", "pku_training_y.utf8")
    split_into_x_y("pku_test_seg.utf8", "pku_test_x.utf8", "pku_test_y.utf8")