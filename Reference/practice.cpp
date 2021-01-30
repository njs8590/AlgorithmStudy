#define HASHMAX 20007
#define ARRMAX 10000

//struct
struct node {
	char data[21];
	node* next;
}nodepool[ARRMAX];

struct trieNode {
	trieNode* child[26];
	bool isWord;
}nodepool_trie[ARRMAX];

//pre-defined
int key_hash(char *str);
void in_hash(char *str);
int m_strcmp(char *str1, char *str2);
void m_strcpy(char *from, char *to);
int find(int x);
void m_union(int x, int y);
void merge_sort(int arr[], int N);
node* myalloc();
trieNode* myalloc_trie();
void in_trie(trieNode* root, char *str);
bool find_trie(trieNode* root, char *str);
int m_sizeof(char *str);

//global var
int nodepool_index = 0;
int nodepol_trie_index = 0;
node* BUCKET[HASHMAX];
int parent[ARRMAX];
int temp[ARRMAX];

//function define
trieNode* myalloc_trie() {
	trieNode* newp;
	newp = &nodepool_trie[nodepol_trie_index++];
	for (int i = 0; i < 26; i++) {
		newp->child[i] = 0;
	}
	newp->isWord = false;
	return newp;
}
void in_trie(trieNode* root, char *str) {
	trieNode *temp;
	temp = root;
	for (int i = 0; i < m_sizeof(str); i++) {
		//현재알파벳
		int cur = str[i] - 'a';
		//없다면 추가
		if (!temp->child[cur]) {
			temp->child[cur] = myalloc_trie();
		}
		//다음알파벳
		temp = temp->child[cur];
	}
	temp->isWord = true;
}
bool find_trie(trieNode* root, char *str) {
	trieNode* temp;
	temp = root;
	for (int i = 0; i < m_sizeof(str); i++) {
		int cur = str[i] - 'a';
		if (temp->child[cur] == 0) {
			return false;
		}
		temp = temp->child[cur];
	}
	return temp != 0 && temp->isWord;
}

int m_sizeof(char *str) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}
node* myalloc() {
	return &nodepool[nodepool_index++];
}
int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}
void m_union(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y) {
		parent[x] = y;
	}
}
void merge_sort(int arr[], int N) {
	if (N == 0)return;
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
int key_hash(char *str) {
	int hash = 5381;
	int c;
	while (c = *str++) {
		hash = (((hash << 5) + c) + hash) % HASHMAX;
	}
	return hash;
}
void in_hash(char *str) {
	int key = key_hash(str);
	node* newp;
	newp = myalloc();
	m_strcpy(str, newp->data);
	newp->next = BUCKET[key];
	BUCKET[key] = newp;
}
int m_strcmp(char *str1, char *str2) {
	int i = 0;
	while (str1[i]) {
		if (str1[i] != str2[i]) {
			return 1;
		}
		i++;
	}
	if (str2[i] != '\0')
		return 1;
	return 0;
}
void m_strcpy(char *from, char *to) {
	int i = 0;
	while (from[i]) {
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}
