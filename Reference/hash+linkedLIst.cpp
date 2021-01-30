#include<iostream>

#define NODEPOOL 25000
#define WORD 10000
#define HASHMAX WORD*2+7
#define TABLE_SIZE 10000

struct node {
	node* next;
	char data[7];

}nodepool[NODEPOOL];

int nodepool_index = 0;

node* myalloc() {
	return &nodepool[nodepool_index++];
}

node* BUCKET[TABLE_SIZE];

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
	strcpy(newp->data, str);
	newp->next = BUCKET[key];
	BUCKET[key] = newp;
}

int main(void) {
	return 0;
}