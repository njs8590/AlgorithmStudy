//https://www.acmicpc.net/problem/5670
#define TRIEMAX 1000
#define ARRMAX 1000

#include<stdio.h>

//struct
struct trieNode {
	trieNode* child[26];
	bool isWord;
}trieNodepool[TRIEMAX];

//function pre-defined
trieNode* myalloc_trie();
void in_trie(trieNode* root, char *str);
int search_trie(trieNode* root, char *str);
int m_sizeof(char *str);

//global var
int index_trieNodepool;

//function defined
trieNode* myalloc_trie() {
	trieNode* newp;
	for (int i = 0; i < 26; i++) {
		newp->child[i] = 0;
	}
	newp->isWord = false;

	return newp;
}
void in_trie(trieNode* root, char *str) {
	trieNode* temp;
	temp = root;

	for (int i = 0; i < m_sizeof(str); i++) {
		if (temp->child[i] == 0) {
			temp->child[i] = myalloc_trie();
		}
		temp = temp->child[i];
	}
	temp->isWord = true;
}

int main(void) {

	return 0;
}