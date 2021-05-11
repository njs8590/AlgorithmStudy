# PROBLEM: A+B - 8
# LINK: https://www.acmicpc.net/problem/11022
# ALGORITHM: -

T = int(input())

for case in range(1, T+1) :
    a, b = map(int, input().split())
    print("Case #"+str(case)+": "+str(a)+" + "+str(b)+" = ", end = '')
    print(a+b)