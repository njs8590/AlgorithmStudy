# PROBLEM: 알람시계
# LINK: https://www.acmicpc.net/problem/2884
# ALGORITHM: -

h, m = map(int, input().split())

if m-45 < 0:
    if h==0:
        h = 23
    else:
        h = h-1
    m = m+15
else:
    m = m-45

print(h, end=' ')
print(m)
