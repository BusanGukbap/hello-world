#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int N, M;
int arr[100001];
pair<int, int>* Tree; // <minVal, maxVal>

pair<int, int> makeTree(int start, int end, int node) {
	if (start == end) {
		Tree[node].first = Tree[node].second = arr[start];
		return Tree[node];
	}

	int mid = (start + end) / 2;
	pair<int, int> a = makeTree(start, mid, node * 2);
	pair<int, int> b = makeTree(mid + 1, end, node * 2 + 1);
	Tree[node].first = (a.first < b.first) ? a.first : b.first;
	Tree[node].second = (a.second > b.second) ? a.second : b.second;

	return Tree[node];
}

pair<int, int> findVal(int start, int end, int node, int left, int right) {
	// out of bound
	if (end < left || right < start) {
		return { 1000000001, 0 };
	}
	if (left <= start && end <= right) {
		return Tree[node];
	}

	int mid = (start + end) / 2;
	pair<int, int> a = findVal(start, mid, node * 2, left, right);
	pair<int, int> b = findVal(mid + 1, end, node * 2 + 1, left, right);
	pair<int, int> c;
	c.first = (a.first < b.first) ? a.first : b.first;
	c.second = (a.second > b.second) ? a.second : b.second;
	
	return c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	int height = ceil(log2(N));
	Tree = new pair<int, int>[1 << (height + 1)];

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	makeTree(1, N, 1);

	int a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		pair<int, int> temp = findVal(1, N, 1, a, b);
		cout << temp.first << ' ' << temp.second << '\n';
	}


	delete[] Tree;

	return 0;
}