
# ----------- 입출력 ----------- #
# 공백을 구분으로 입력
A,B,C = map(int, input().split())
# 출력 후 처리
print(h, end=' ')
# 리스트 입력처리
arr = list(map(int, input().split()))

# ----------- 반복문 ----------- #

# ----------- 리스트 ----------- #
# 특정원소 위치반환
print(arr.index(max(arr))+1)
# 문자열을 한문자씩 분리하여 리스트에 입력
res = list(str(A*B*C))
# 특정문자가 포함된 개수를 반환
print(res.count(str(i)))