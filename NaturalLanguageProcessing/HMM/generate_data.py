
def split_raw_data(file_path, flag="train"):
    x, y = [], []
    with open(file_path, 'r', encoding='utf-8') as f:
        raw_data = f.readlines()
    for sen in raw_data:
        sen = sen.rstrip('\n')
        words = sen.split()
        sen_x = []
        sen_y = []
        for word in words:
            i = word.split("/")
            if(len(i)==2):
                sen_x.append(i[0])
                sen_y.append(i[1])
        if len(sen_x):
            x.append(sen_x)
            y.append(sen_y)

    with open(f"./{flag}_x.txt", 'w', encoding='utf-8') as f:
        for sen in x:
            f.write(" ".join(sen))
            f.write("\n")
    with open(f"./{flag}_y.txt", 'w', encoding='utf-8') as f:
        for sen in y:
            f.write(" ".join(sen))
            f.write("\n")


if __name__ == "__main__":
    file_path = r"./test1998people_daily.txt"
    split_raw_data(file_path, flag="test")