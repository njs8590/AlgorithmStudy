# PROBLEM: 최댓값
# LINK: https://www.acmicpc.net/problem/2562
# ALGORITHM: -

arr = []
for i in range(0, 9):
    arr.append(int(input()))
print(max(arr))
print(arr.index(max(arr))+1)

