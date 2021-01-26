//https://www.acmicpc.net/problem/1991
//트리 기본유형

#include<stdio.h>
#include<iostream>

using namespace std;

struct node {
	char data;
	node* left;
	node* right;
}nodepool[40];

int idx_nodepool = 0;

node* myalloc() {
	node* newp;
	newp = &nodepool[idx_nodepool++];
	newp->left = 0;
	newp->right = 0;
	return newp;
}

node* root;
node* curNode;

void findNode(node* node, char data) {
	if (node == 0) {
		return;
	}

	if (node->data == data) {
		curNode = node;
		//cout << "findNode" << endl;
	}
	findNode(node->left, data);
	findNode(node->right, data);

}

void preOrder(node* node) {
	if (node == 0) {
		return;
	}
	cout << node->data;
	preOrder(node->left);
	preOrder(node->right);
}

void inOrder(node* node) {
	if (node == 0) {
		return;
	}
	inOrder(node->left);
	cout << node->data;
	inOrder(node->right);
}

void postOrder(node* node) {
	if (node == 0) {
		return;
	}
	postOrder(node->left);
	postOrder(node->right);
	cout << node->data;
}

int main(void) {

	root = myalloc();
	root->data = 'A';
	curNode = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char rootData, rightData, leftData;

		cin>>rootData>>leftData>>rightData;

		findNode(root, rootData);
		if (curNode != 0) {
			if (leftData != '.') {
				node* newleft;
				newleft = myalloc();
				newleft->data = leftData;
				curNode->left = newleft;
			}

			if (rightData != '.') {
				node* newRight;
				newRight = myalloc();
				newRight->data = rightData;
				curNode->right = newRight;
			}
		}
	}

	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;

	return 0;
}