#define MAX 10000

int temp[MAX];

void merge_sort(int arr[], int N) {
	if (N == 1)return;
	int nxtN = N / 2;

	merge_sort(arr, nxtN);
	merge_sort(arr+nxtN, N - nxtN);

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
