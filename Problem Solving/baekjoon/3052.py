# PROBLEM: 나머지
# LINK: https://www.acmicpc.net/problem/3052
# ALGORITHM: -
# 수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다. 그 다음 서로 다른 값이 몇 개 있는지 출력하는 프로그램을 작성하시오.

numbers = []
answer = []
for i in range(0,10):
    temp = int(input()) % 42
    numbers.append(temp)
    if answer.count(temp) == 0:
        answer.append(temp)

print(len(answer))