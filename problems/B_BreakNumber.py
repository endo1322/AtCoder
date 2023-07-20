'''https://atcoder.jp/contests/abc068/tasks/abc068_b'''

def main():
    N = int(input())
    max_cnt = 0
    best_i = 1
    for i in range(1, N+1):
        cnt = 0
        ii = i
        while True:
            dev = ii / 2
            if dev == 0:
                cnt += 1
                break
            elif dev.is_integer:
                cnt += 1
                ii = int(dev)
            else:
                break
        if cnt > max_cnt:
            max_cnt = cnt
            best_i = i
    print(best_i)

if __name__ == '__main__':
    main()