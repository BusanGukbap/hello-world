#include <iostream>

using namespace std;

int N, M;
int arr[100001];
int tree[200001];

// Make SegmentTree
// start : current start index, end : current end index, node : node number in SegmentTree
int init(int start, int end, int node) {
	if (start == end) {
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	int a = init(start, mid, node * 2);
	int b = init(mid+1, end, node * 2 + 1);
	return tree[node] = (a < b) ? a : b;
}

// find MinVal in Left~Right
int findMin(int start, int end, int node, int left, int right) {
	// Out of Bound
	if (right < start || end < left) {
		return 1000000001;
	}
	// within Bound
	if (left <= start && end <= right) {
		return tree[node];
	}
	// ¹İ¹İ
	int mid = (start + end) / 2;
	int a = findMin(start, mid, node * 2, left, right);
	int b = findMin(mid + 1, end, node * 2 + 1, left, right);
	return (a < b) ? a : b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	
	// Make Segment Tree
	init(1, N, 1);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << findMin(1, N, 1, a, b) << '\n';
	}


	return 0;
}