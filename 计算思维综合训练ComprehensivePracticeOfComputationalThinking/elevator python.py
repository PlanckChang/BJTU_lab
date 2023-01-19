import functools
count = 1
def find_the_limit(comd):
    # to find the floor
    if len(comd) == 0:
        return 0, 0, 0
    dic = []
    for i in comd:
        t = i.split('-')
        dic.append(t[0])
        dic.append(t[1])
    dic = list(set(dic))
    dic = [int(i) for i in dic]
    dic.sort()
    return dic[0], dic[-1], len(dic)
def get_data_list(x, y):
    # up down list to be sorted
    if x[0] < y[0]:
        return -1
    elif x[0] > y[0]:
        return 1
    else:
        return 0
def go_up():
    global stop_time, runing_time, N, up, down
    up_n, up_b = find_permit_move('up')
    if up_n == 0:
        # no up demand
        dir_continue()
        return
    st = up_b[0]
    low, hign, stops = find_the_limit(up_b)
    stairs_time = (hign - N) * u
    runing_time += stairs_time
    if low == N:
        stop_time += (stops - 1) * s
    else:
        stop_time += stops * s
    for i in range(len(up_b)):
        up.remove(up_b[i])
    N = hign
    # up to top
    dir_continue()
def find_permit_move(dire):
    global up, down
    up_n = down_n = 0
    up_b = down_b = []
    if dire == 'up':
        for i in up:
            t = i.split('-')
            if int(t[0]) >= N:
                up_n += 1
                up_b.append(i)
        return up_n, up_b
    elif dire == 'down':
        for j in down:
            t = j.split('-')
            if int(t[0]) <= N:
                down_n += 1
                down_b.append(j)
        return down_n, down_b
def go_down():
    global stop_time, runing_time, N, up, down
    down_n, down_b = find_permit_move('down')
    if down_n == 0:
        # on down demand
        dir_continue()
        return
    st = down_b[len(down_b) - 1]
    low, hign, stops = find_the_limit(down_b)
    runing_time += (N - low) * d
    if hign == N:
        stop_time += (stops - 1) * s
    else:
        stop_time += stops * s
    for i in range(len(down_b)):
        down.remove(down_b[i])
    N = low
    # down to below
    dir_continue()
def dir_continue():
    global up, down, direct, N, runing_time, stop_time
    minn = 200
    max_x = 0
    if direct == 'down':
        for i in up:
            # to judge to go no or not
            t = i.split('-')
            if int(t[0]) < N and int(t[0]) < minn:
                minn = int(t[0])
        if minn == 200:
            return 0
        else:
            runing_time += (N - minn) * d
            stop_time += s
            N = minn
            return 1
    else:
        max_x = 0
        for i in down:
            t = i.split('-')
            if int(t[0]) > N and int(t[0]) > max_x:
                max_x = int(t[0])
        if max_x == 0:
            return 0
        else:
            runing_time += (max_x - N) * u
            stop_time += s
            N = max_x
            return 1
def turn_around():
    global direct
    if direct == 'up':
        direct = 'down'
        go_down()
    else:
        direct = 'up'
        go_up()
def start_rolling():
    global direct
    if direct == 'up':
        go_up()
    else:
        direct = 'down'
        go_down()
while True:
    try:
        str_in = input().split()
        N, u, d, s = [int(i) for i in str_in]
        n = N
        print("Case {}:".format(count), end=' ')
        cmd = input().split()
        cmd = list(set(cmd))
        up = []
        down = []
        ans = time_up = time_down = 0
        stop_time = runing_time = 0
        direct = ''
        start = ''
        for i in cmd:
            t = i.split('-')
            if int(t[1]) > int(t[0]):
                up.append(i)
            else:
                down.append(i)
        up = sorted(up, key=functools.cmp_to_key(get_data_list))
        down = sorted(down, key=functools.cmp_to_key(get_data_list))
        up_ = up[:]
        down_ = down[:]
        # up down up
        direct = 'up'
        start_rolling()
        while len(up) != 0 or len(down) != 0:
            turn_around()
        time_up = runing_time + stop_time
        # down up down
        N = n
        stop_time = runing_time = 0
        up = up_
        down = down_
        direct = 'down'
        start_rolling()
        while len(up) != 0 or len(down) != 0:
            turn_around()
        time_down = runing_time + stop_time
        ans = min(time_down, time_up)
        print(ans)
        count += 1  ###
    except:
        break