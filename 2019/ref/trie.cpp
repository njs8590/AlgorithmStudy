#include<stdio.h>

#define TRIEMAX 10000

struct trieNode {
	trieNode* child[26];
	bool isWord;
}trieNodepool[TRIEMAX];

int index_trienodepool = 0;

//function pre-defined
trieNode* myalloc_trie();
void trie_insert(trieNode* root, char* str);
bool trie_search(trieNode* root, char *str);
int m_sizeof(char* str);

trieNode* myalloc_trie() {
	trieNode* newp;
	newp = &trieNodepool[index_trienodepool++];

	for (int i = 0; i < 26; i++) {
		newp->child[i] = 0;
	}
	newp->isWord = false;

	return newp;
}

void trie_insert(trieNode* root, char* str) {
	trieNode* temp = root;
	for (int i = 0; i < m_sizeof(str); i++) {
		int index = str[i] - 'a';
		if (!temp->child[index]) {
			//이어지는 알파벳이 없다면, 새로 할당
			temp->child[index] = myalloc_trie();
		}
		//다음 알파벳으로 진행
		temp = temp->child[index];
	}
	//알파벳 하나하나 넣고, 마지막 알파벳에 word 체크
	temp->isWord = true;

	printf("trieInsert_complete\n");
}

bool trie_search(trieNode* root, char* str) {
	trieNode* temp = root;
	for (int i = 0; i < m_sizeof(str); i++) {
		//찾고자 하는 단어의 알파벳 하나하나 체크
		int index = str[i] - 'a';

		if (!temp->child[index]) {
			//찾고자 하는 단어의 현재알파벳이 존재하지 않는다면 false 리턴
			return false;
		}
		//계속해서 다음 알파벳으로 진행
		temp = temp->child[index];
	}
	
	return (temp != 0 && temp->isWord);
}

int m_sizeof(char *str) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}

int main(void) {
	
	trieNode* root;
	root = myalloc_trie();

	int testcase = 0;
	scanf("%d", &testcase);

	for (int t = 0; t < testcase; t++) {
		printf("data::");
		char data[10];
		scanf("%s", &data);
		trie_insert(root, data);

		printf("search::");
		char search[10];
		scanf("%s", &search);
		trie_search(root, search) ? printf("yes\n") : printf("no\n");

	}

	return 0;
}