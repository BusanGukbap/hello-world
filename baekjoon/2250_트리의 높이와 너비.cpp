#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;

typedef struct node {
	int data;
	int left_child_number;
	int right_child_number;
	int location;
} node;

node Tree[10001];
int idx = 1;
int width[10001][2]; // 왼쪽 끝, 오른쪽 끝
int parent[10001];

void func(int node_number, int level) {
	// 왼쪽 자식 있으면 먼저 감
	if (Tree[node_number].left_child_number != -1) {
		func(Tree[node_number].left_child_number, level+1);
	}

	// 본인 위치 지정
	Tree[node_number].location = idx++;
	if (width[level][0] == 0) {
		width[level][0] = width[level][1] = Tree[node_number].location;
	}
	else if (width[level][1] < Tree[node_number].location)
		width[level][1] = Tree[node_number].location;

	// 오른쪽 자식 있으면 감
	if (Tree[node_number].right_child_number != -1) {
		func(Tree[node_number].right_child_number, level + 1);
	}

	return;
}

int find_root() {
	for (int i = 1; i <= N; i++) {
		if (parent[i] == 0)
			return i;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int NN, LC, RC;

	cin >> N;

	for (int i = 1; i <= 10000; i++)
		Tree[i].data = -1;

	for (int i = 0; i < N; i++) {
		cin >> NN >> LC >> RC;
		Tree[NN].data = NN;
		Tree[NN].left_child_number = LC;
		Tree[NN].right_child_number = RC;
		parent[LC] = NN;
		parent[RC] = NN;
	}

	func(find_root(), 1);

	int result_level = 1, result_width = 0;
	for (int i = 2; ; i++) {
		if (width[i][0] == 0 && width[i][1] == 0)
			break;
		
		int temp = width[i][1] - width[i][0];
		if (result_width < temp) {
			result_width = temp;
			result_level = i;
		}
	}

	cout << result_level << " " << result_width+1 << '\n';

	return 0;
}