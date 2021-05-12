# PROBLEM: 평균
# LINK: https://www.acmicpc.net/problem/1546
# ALGORITHM: -

N= int(input())
scores = list(map(int, input().split()))

max_score = max(scores)
answer = 0
for i in range(0,len(scores)):
    answer += scores[i]/max_score*100
print(answer/N)
