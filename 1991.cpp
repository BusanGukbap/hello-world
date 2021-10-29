#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef struct tree* treePointer;
typedef struct tree {
	char data;
	treePointer left;
	treePointer right;
};
tree Bin_tree[26];

void preorder(treePointer index) {
	if (index) {
		cout << index->data;
		preorder(index->left);
		preorder(index->right);
	}
}

void inorder(treePointer index) {
	if (index) {
		inorder(index->left);
		cout << index->data;
		inorder(index->right);
	}
}

void postorder(treePointer index) {
	if (index) {
		postorder(index->left);
		postorder(index->right);
		cout << index->data;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	char input, left, right;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input >> left >> right;
		Bin_tree[input - 'A'].data = input;
		if (left != '.')
			Bin_tree[input - 'A'].left = &Bin_tree[left - 'A'];
		else
			Bin_tree[input - 'A'].left = NULL;
		if (right != '.')
			Bin_tree[input - 'A'].right = &Bin_tree[right - 'A'];
		else
			Bin_tree[input - 'A'].right = NULL;
	}
	
	preorder(&Bin_tree[0]); cout << '\n';
	inorder(&Bin_tree[0]); cout << '\n';
	postorder(&Bin_tree[0]); cout << '\n';

	return 0;
}