'''https://atcoder.jp/contests/abc138/tasks/abc138_c'''

def main():
    N = int(input())
    v = list(map(int, input().split()))

    v.sort()
    for _ in range(len(v)-1):
        v1 = v.pop(0)
        v2 = v.pop(0)
        new_v = (v1+v2)/2
        v.insert(0, new_v)

    print(v[0])

if __name__ == '__main__':
    main()