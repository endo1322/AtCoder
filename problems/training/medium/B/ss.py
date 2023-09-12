'''https://atcoder.jp/contests/abc066/tasks/abc066_b'''

def main():
    S = list(input())
    del S[-1]
    while True:
        if len(S) % 2 != 0:
            del S[-1]
            continue
        mae = S[0:int(len(S)/2)-1]
        ato = S[int(len(S)/2):-1]

        if mae == ato:
            ans = len(S)
            break
        else:
            del S[-1]

    print(ans)

if __name__ == '__main__':
    main()