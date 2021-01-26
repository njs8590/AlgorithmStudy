//https://www.acmicpc.net/problem/5052

#define NODEMAX 100007
#define ARRMAX 10007
#define TRIEMAX 10
#include<stdio.h>

//struct
struct trieNode {
	trieNode* child[TRIEMAX];
	bool isWord;
}trieNodepool[NODEMAX];

//function pre-defined
void in_trie(trieNode* root, char *str);
bool find_trie(trieNode* root, char *str);
trieNode* myalloc_trie();
int m_sizeof(char *str);

//global variable
int index_trieNodepool = 0;

//function define
void in_trie(trieNode* root, char *str) {
	trieNode* temp;
	temp = root;
	for (int i = 0; i < m_sizeof(str); i++) {
		int cur = str[i] - '0';

		if (!temp->child[cur]) {
			temp->child[cur] = myalloc_trie();
		}
		temp = temp->child[cur];
	}
	temp->isWord = true;

}
bool find_trie(trieNode* root, char *str) {
	trieNode* temp;
	temp = root;
	for (int i = 0; i < m_sizeof(str); i++) {
		int cur = str[i] - '0';
		if (!temp->child[cur]) {
			return false;
		}
		temp = temp->child[cur];
	}
	bool check = false;
	for (int i = 0; i < 10; i++) {
		if (temp->child[i]) {
			check = true;
			break;
		}
	}
	return check;
}

int m_sizeof(char *str) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}

trieNode* myalloc_trie() {
	trieNode* newp;
	newp = &trieNodepool[index_trieNodepool++];
	for (int i = 0; i < TRIEMAX; i++) {
		newp->child[i] = 0;
	}
	newp->isWord = false;

	return newp;
}

int main(void) {
	int testcase;
	scanf("%d", &testcase);

	for (int t = 0; t < testcase; t++) {
		int number;
		index_trieNodepool = 0;

		trieNode* root;
		root = myalloc_trie();
		
		scanf("%d", &number);
		bool find_answer = false;
		
		char newNumber[ARRMAX][11];

		for (int n = 0; n < number; n++) {
			scanf("%s", &newNumber[n]);
			in_trie(root, newNumber[n]);
		}

		for (int n = 0; n < number; n++) {
			find_answer = find_trie(root, newNumber[n]);
			if (find_answer) {
				//printf("find:%s", newNumber[n]);
				break;
			}
		}

		if (find_answer) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}