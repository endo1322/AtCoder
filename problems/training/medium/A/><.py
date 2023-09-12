'''https://atcoder.jp/contests/agc040/tasks/agc040_a'''

def main():
    S = list(input())
    c_max = 0
    ans = 0
    c_mini = 0
    c_max = 0
    flag_mini = True
    for s in S:
        if s == '<' and flag_mini:
            # flag_mini = True
            c_mini += 1
        elif s == '<':
            if c_mini > c_max:
                c_max = c_max - 1
            else:
                c_mini = c_mini - 1
            mini_sum = (c_mini * (c_mini + 1) // 2)
            max_sum = (c_max * (c_max + 1) // 2)
            ans += mini_sum + max_sum
            flag_mini = True
            c_mini = 1
            c_max = 0
        elif s == '>':
            flag_mini = False
            c_max += 1

    if c_mini > c_max:
        c_max = c_max - 1
    else:
        c_mini = c_mini - 1
    mini_sum = (c_mini * (c_mini + 1) // 2)
    max_sum = (c_max * (c_max + 1) // 2)
    ans += mini_sum + max_sum

    print(ans)

if __name__ == '__main__':
    main()