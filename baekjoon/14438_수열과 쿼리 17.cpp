#include <iostream>
#include <cmath>

using namespace std;

int N, M;
int arr[100001];
int* Tree;

int init(int start, int end, int node) {
	if (start == end) {
		return Tree[node] = arr[start];
	}
	
	int mid = (start + end) / 2;
	int a = init(start, mid, node * 2);
	int b = init(mid + 1, end, node * 2 + 1);

	Tree[node] = min(a, b);
	return Tree[node];
}

void update(int node) {
	if (node == 0)
		return;

	Tree[node] = (Tree[node * 2] < Tree[node * 2 + 1]) ? Tree[node * 2] : Tree[node * 2 + 1];
	update(node / 2);
}

void changeNode(int start, int end, int node, int index, int data) {
	if (start == end) {
		arr[index] = data;
		Tree[node] = data;
		update(node / 2);
		return;
	}

	int mid = (start + end) / 2;
	if (index <= mid)
		changeNode(start, mid, node * 2, index, data);
	else
		changeNode(mid + 1, end, node * 2 + 1, index, data);
}

int findMin(int start, int end, int node, int left, int right) {
	// out of bound
	if (right < start || end < left)
		return 1000000000;

	// within bound
	if (left <= start && end <= right)
		return Tree[node];

	int mid = (start + end) / 2;
	int a = findMin(start, mid, node * 2, left, right);
	int b = findMin(mid + 1, end, node * 2 + 1, left, right);

	if (mid < left) {
		a = 1000000000;
	}
	if (mid >= right)
		b = 1000000000;

	return min(a, b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	int height = ceil(log2(N));
	Tree = new int[1 << (height + 1)];
	init(1, N, 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		switch (a) {
		case 1:
			changeNode(1, N, 1, b, c);
			break;
		case 2:
			cout << findMin(1, N, 1, b, c) << '\n';
			break;
		}
	}


	return 0;
}