/*****
https://www.acmicpc.net/problem/1920
이분탐색문제
이분탐색 썼는데 시간초과 난다..
왜틀리는지 모르겠다..
*****/

#define MAX 100001
#include<iostream>
#include<algorithm>

using namespace std;

int binary_search(int arr[], int size, int check);
void merge_sort(int arr[], int N);


int temp[MAX];
void merge_sort(int arr[], int N) {
	if (N == 1)return;
	int nxtN = N / 2;

	merge_sort(arr, nxtN);
	merge_sort(arr + nxtN, N - nxtN);

	int i, j, k;
	i = k = 0;
	j = nxtN;

	while (i < nxtN && j < N) {
		temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	}
	while (i < nxtN) {
		temp[k++] = arr[i++];
	}
	while (j < N) {
		temp[k++] = arr[j++];
	}

	for (int i = 0; i < N; i++) {
		arr[i] = temp[i];
	}
}

int main(void) {
	//input: N, A[N], M, B[M]
	int N, M;
	int A[MAX], B[MAX];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	//merge_sort(A, N);
	sort(A, A + N);
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> B[i];
		int answer = binary_search(A, N, B[i]);
		cout << answer << endl;
	}
	return 0;
}

int binary_search(int arr[], int size, int check) {

	int mid = arr[size / 2];
	if (mid == check) return 1;
	if (size == 1) return 0;

	if (mid > check) {
		return binary_search(arr, size / 2, check);
	}
	else if (mid < check) {
		return binary_search(arr + size / 2, size - size / 2, check);
	}

	return 0;
}