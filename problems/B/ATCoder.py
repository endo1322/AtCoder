'''https://atcoder.jp/contests/abc122/tasks/abc122_b'''

def main():
    S = list(input())
    
    setACGT = set(['A', 'C', 'G', 'T'])
    max = 0

    count = 0
    for s in S:
        if s in setACGT:
            count += 1
        else:
            count = 0
        if count > max:
            max = count

    print(max)

if __name__ == '__main__':
    main()