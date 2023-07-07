

def combine_seg(input_file, output_file):
    with open(input_file, "r") as f1, open(output_file, "w") as f2:
        flag = 1
        for line in f1.readlines():
            if line == "\n":
                f2.write(line)
                flag = 1
            else:
                word, _,  tag = line.strip().split()
                if tag == "B":
                    if flag == 1:
                        f2.write(word)
                    else:
                        f2.write(" "+word)
                elif tag == "M":
                    f2.write(word)
                elif tag == "E":
                    f2.write(word+" ")
                elif tag == "S":
                    f2.write(" "+word+" ")
                flag = 0


if __name__ == "__main__":
    combine_seg("./data/train_eval.txt", "train_eval_combine.txt")
    combine_seg("./data/test_eval.txt", "test_eval_combine.txt")
    print("combine done")