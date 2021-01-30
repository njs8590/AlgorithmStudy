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
			//�̾����� ���ĺ��� ���ٸ�, ���� �Ҵ�
			temp->child[index] = myalloc_trie();
		}
		//���� ���ĺ����� ����
		temp = temp->child[index];
	}
	//���ĺ� �ϳ��ϳ� �ְ�, ������ ���ĺ��� word üũ
	temp->isWord = true;

	printf("trieInsert_complete\n");
}

bool trie_search(trieNode* root, char* str) {
	trieNode* temp = root;
	for (int i = 0; i < m_sizeof(str); i++) {
		//ã���� �ϴ� �ܾ��� ���ĺ� �ϳ��ϳ� üũ
		int index = str[i] - 'a';

		if (!temp->child[index]) {
			//ã���� �ϴ� �ܾ��� ������ĺ��� �������� �ʴ´ٸ� false ����
			return false;
		}
		//����ؼ� ���� ���ĺ����� ����
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