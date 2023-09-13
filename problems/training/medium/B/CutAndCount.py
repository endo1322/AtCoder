'''https://atcoder.jp/contests/abc098/tasks/abc098_b'''

def main():
    N = int(input())
    S = list(input())
    
    max = 0
    for i in range(1, N-1):
        mae = S[0:i]
        set_mae = set(mae)
        ato = S[i:]
        set_ato = set(ato)
        tmp = len(set_mae & set_ato)
        if tmp > max:
            max = tmp
    print(max)

if __name__ == '__main__':
    main()