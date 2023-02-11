#include <iostream>
#include <cmath>

using namespace std;

int N, M;
int height;
int arr[100010];
pair<int, int>* Tree; // <data, index>

pair<int, int> makeTree(int start, int end, int node) {
	if (start == end) {
		return Tree[node] = { arr[start], start };
	}
	
	int mid = (start + end) / 2;
	pair<int, int> a = makeTree(start, mid, node * 2);
	pair<int, int> b = makeTree(mid + 1, end, node * 2 + 1);

	if (a.first < b.first || (a.first == b.first && a.second < b.second)) {
		return Tree[node] = { a.first, a.second };
	}
	else {
		return Tree[node] = { b.first, b.second };
	}
}

void updateTree(int node) {
	if (node == 0)
		return;

	if (Tree[node * 2].first < Tree[node * 2 + 1].first)
		Tree[node] = Tree[node * 2];
	else if (Tree[node * 2].first == Tree[node * 2 + 1].first && Tree[node * 2].second < Tree[node * 2 + 1].second)
		Tree[node] = Tree[node * 2];
	else
		Tree[node] = Tree[node * 2 + 1];
	
	updateTree(node / 2);
}

void changeData(int start, int end, int node, int Idx, int data) {
	if (start == end) {
		arr[Idx] = data;
		Tree[node].first = data;
		updateTree(node/2);
		return;
	}

	int mid = (start + end) / 2;
	if (mid < Idx) {
		changeData(mid + 1, end, node * 2 + 1, Idx, data);
	}
	else {
		changeData(start, mid, node * 2, Idx, data);
	}
}

pair<int, int> findMin(int start, int end, int node, int left, int right) {
	// out of bound
	if (end < left || right < start) {
		return { 1000000001, 1000000001 };
	}

	// within bound
	if (left <= start && end <= right) {
		return Tree[node];
	}

	// ¹İ¹İ
	int mid = (start + end) / 2;
	pair<int, int> a = findMin(start, mid, node * 2, left, right);
	pair<int, int> b = findMin(mid+1, end, node * 2 + 1, left, right);
	if (a.first < b.first || (a.first == b.first && a.second < b.second)) {
		return a;
	}
	else
		return b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	height = ceil(log2(N));
	Tree = new pair<int, int>[1 << (height + 1)];
	makeTree(1, N, 1);

	cin >> M;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		switch (a) {
		case 1:
			changeData(1, N, 1, b, c);
			//for (int j = 1; j < (1 << (height + 1)); j++) {
			//	cout << Tree[j].second << ' ';
			//}
			//cout << '\n';
			break;
		case 2:
			pair<int, int> temp = findMin(1, N, 1, b, c);
			cout << temp.second << '\n';
			break;
		}
	}
	return 0;
}