# PROBLEM: A+B - 7
# LINK: https://www.acmicpc.net/problem/11021
# ALGORITHM: -

T = int(input())

for case in range(1, T+1) :
    a, b = map(int, input().split())
    print("Case #"+str(case)+": ", end = '')
    print(a+b)