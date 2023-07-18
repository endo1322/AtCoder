import pprint

def main():
    N, M = map(int, input().split())
    if not(2 <= N <= 100 and 1 <= M <= 100):
        print('No')
        return
    all = []
    for _ in range(N):
        data = input().split()
        if not(1 <= int(data[1]) <= M):
            print('No')
            return
        if len(data[2:]) != int(data[1]):
            print('No')
            return
        for d in data[2:]:
            if not(1 <= int(d) <= M):
                print('No')
                return
        all.append([int(data[0]), int(data[1]), list(map(int, data[2:]))])
    # print(all)

    all.sort(key=lambda x : x[0])
    # print(all)
    # pprint.pprint(all)
    for i in range(N):
        price_a = all[i][0]
        count_a = all[i][1]
        func_a = all[i][2]
        for j in range(i+1, N):
            price_b = all[j][0]
            count_b = all[j][1]
            func_b = all[j][2]
            flag = True
            for f in func_b:
                if f not in func_a:
                    flag = False
            if flag == True:
                if price_b > price_a or count_a > count_b:
                    # print(all[i], all[j])
                    print('Yes')
                    return
            else:
                continue
            # if count_a < count_b:
            #         continue
            # elif count_a == count_b:
            #     if price_a == price_b:
            #           continue
            #     for f in func_b:
            #         if f not in func_a:
            #             continue
            #     print('Yes')
            #     return
            # else:
            #     for f in func_b:
            #         if f not in func_a:
            #             continue
                
            #     print('Yes')
            #     return

    print('No')          

if __name__ == '__main__':
    main()

'''
in
5 6
10000 2 1 3
15000 3 1 2 4
30000 3 1 3 5
35000 2 1 5
100000 6 1 2 3 4 5 6

in
20 10
72036 3 3 4 9
7716 4 1 2 3 6
54093 5 1 6 7 8 10
25517 7 3 4 5 6 7 9 10
96930 8 2 3 4 6 7 8 9 10
47774 6 2 4 5 6 7 9
36959 5 1 3 4 5 8
46622 7 1 2 3 5 6 8 10
34315 9 1 3 4 5 6 7 8 9 10
54129 7 1 3 4 6 7 8 9
4274 5 2 4 7 9 10
16578 5 2 3 6 7 9
61809 4 1 2 4 5
1659 5 3 5 6 9 10
59183 5 1 2 3 4 9
22186 4 3 5 6 8
98282 4 1 4 7 10
72865 8 1 2 3 4 6 8 9 10
33796 6 1 3 5 7 9 10
74670 4 1 2 6 8


'''