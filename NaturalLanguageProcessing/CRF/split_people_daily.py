

def split_people_daily(input_file, output_file):
    with open(input_file, "r", encoding="utf-8") as f1, open(output_file, "w", encoding="utf-8") as f2:
        for line in f1.readlines():
            if line == "\n":
                continue
            # print(line)
            for words in line.strip().split():

                tem = words.split("/")
                if len(tem) == 2:
                    word, tag = words.split("/")
                    f2.write(word + "\t" + tag + "\n")
                else:
                    print(tem)
            # sample standard: use a blank line to separate sentences
            f2.write("\n")


if __name__ == "__main__":
    split_people_daily("./data/train1998people_daily.txt", "train_people_daily.txt")
    split_people_daily("./data/test1998people_daily.txt", "test_people_daily.txt")
    print("people daily split done")

