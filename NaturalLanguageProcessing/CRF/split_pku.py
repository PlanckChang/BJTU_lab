
def split_pku(input_file, output_file="pku_split.txt"):
    with open(input_file, "r") as f1, open(output_file, "w") as f2:
        for line in f1.readlines():
            for word in line.strip().split():
                if len(word) == 1:
                    f2.write(word + "\tS\n")
                else:
                    f2.write(word[0] + "\tB\n")
                    for w in word[1:-1]:
                        f2.write(w + "\tM\n")
                    f2.write(word[-1] + "\tE\n")
            # sample standard: use a blank line to separate sentences
            f2.write("\n")


if __name__ == "__main__":
    split_pku("pku_test_gold.txt", "test_pku_split.txt")

