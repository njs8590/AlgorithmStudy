# PROBLEM: 숫자의 개수
# LINK: https://www.acmicpc.net/problem/2577
# ALGORITHM: -

A = int(input())
B = int(input())
C = int(input())
# 문자열을 한문자씩 분리하여 리스트에 입력
res = list(str(A*B*C))
for i in range(0,10):
    cnt = 0
    for res_char in res:
        if res_char == str(i):
            cnt = cnt+1
    print(cnt)

# 특정문자가 포함된 개수를 반환
print(res.count(str(i)))