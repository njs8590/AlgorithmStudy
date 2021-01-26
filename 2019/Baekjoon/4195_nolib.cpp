//https://www.acmicpc.net/problem/4195

#define HASHMAX 200007
#define NODEPOOL 100000
#define ARRMAX 200010

#include<stdio.h>

//struct
struct node {
	char data[21];
	int idx;
	node* next;
}nodepool[100010];

//function pre-defined
int key_hash(char *str);
void in_hash(char *str, int index, int hashkey);
int m_strcmp(char *str1, char *str2);
void m_strcpy(char *from, char *to);
int find(int x);
int m_union(int x, int y);
node* myalloc();
int isInHash(char *str, int hashkey);
void print();

//global var
char f1[21], f2[21];
int nodepool_idx = 0;
node* BUCKET[HASHMAX];
int parent[ARRMAX];
int weight[ARRMAX];

//function defined
node* myalloc() {
	//printf("myalloc\n");
	return &nodepool[nodepool_idx++];
}

int key_hash(char *str) {
	int hash = 5381;
	int c;
	while (c = *str++) {
		hash = (((hash << 5) + c) + hash) % HASHMAX;
	}
	//printf("%s, %d\n",*str, hash);
	return hash;
}
void in_hash(char *str, int index, int hashkey) {
	//printf("in_hash\n");
	int key = hashkey;
	node* newp;
	newp = myalloc();
	m_strcpy(str, newp->data);
	newp->idx = index;
	newp->next = BUCKET[key];
	BUCKET[key] = newp;

	//printf("%s in_hash complete\n",BUCKET[key]->data);
}
int isInHash(char *str, int hashkey) {
	//printf("isinhash?\n");
	int key = hashkey;
	node* temp = BUCKET[key];
	int inHash = 0;

	while (temp) {
		//printf("word: %s\n", temp->data);
		if (m_strcmp(str, temp->data) == 0) {
			inHash = temp->idx;
			//printf("yes\n");
			break;
		}
		temp = temp->next;
	}

	return inHash;
}
void m_strcpy(char *from, char *to) {
	
	int i = 0;
	while (from[i]) {
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
	//printf("strcpy complete\n");
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

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

int m_union(int x, int y) {
	
	x = find(x);
	y = find(y);
	//printf("union! x:%d y:%d\n", x, y);
	

	if (x != y) {
		parent[x] = y;
		weight[y] += weight[x];
		weight[x] = 1;
	}
	
	//print();
	return weight[y];
}

void init() {
	nodepool_idx = 0;

}

int main(void) {

	int testcase;
	scanf("%d", &testcase);

	for (int t = 0; t < testcase; t++) {
		
		int friend_cnt;
		scanf("%d", &friend_cnt);
		//init
		init();

		for (int i = 1; i <= friend_cnt * 2; i++) {
			parent[i] = i;
			weight[i] = 1;
		}

		int hashnum = 1;

		for (int i = 0; i < friend_cnt; i++) {
			
			scanf("%s %s", &f1, &f2);
			
			int key = key_hash(f1);
			int f1_index = isInHash(f1, key);
			//버킷에 있을 경우 해시번호를 반환
			//없을 경우 0을 반환
			if (f1_index == 0) {
				//printf("new word\n");
				in_hash(f1, hashnum, key);
				f1_index = hashnum++;
			}

			key = key_hash(f2);
			int f2_index = isInHash(f2, key);
			if (f2_index == 0) {
				//printf("new word\n");
				in_hash(f2, hashnum, key);
				f2_index = hashnum++;
			}
			
			printf("%d\n", m_union(f1_index, f2_index));
			
		}
		
	}

	return 0;
}

void print() {
	printf("\nweight :");
	for (int i = 0; i < 10; i++) {
		printf(" %d", weight[i]);
	}
	printf("\nparent :");
	for (int i = 0; i < 10; i++) {
		printf(" %d", parent[i]);
	}
}