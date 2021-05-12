# PROBLEM: 별 찍기 - 1
# LINK: https://www.acmicpc.net/problem/2438
# ALGORITHM: -

N = int(input())

for i in range(1, N+1):
    for j in range(1,i+1):
        print("*",end = '')
    print()