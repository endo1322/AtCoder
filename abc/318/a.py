def main():
    N, M, P = map(int, input().split())

    new_ans = M
    count = 0
    while new_ans <= N:
        count += 1
        ans = new_ans
        new_ans = ans + P
    print(count)

if __name__ == '__main__':
    main()