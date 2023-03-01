#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll* tree;
ll arr[100001];
int N, Q;

ll init(int start, int end, int idx) {
	if (start == end) {
		tree[idx] = arr[start];
		return tree[idx];
	}

	int mid = (start + end) / 2;
	return tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
}

void updateTree(int start, int end, int idx, int target, ll diff) {
	// 범위를 벗어난 경우
	if (target < start || target > end)
		return;

	tree[idx] += diff;
	if (start == end)
		return;

	int mid = (start + end) / 2;
	updateTree(start, mid, idx * 2, target, diff);
	updateTree(mid + 1, end, idx * 2 + 1, target, diff);
}

ll getSum(int start, int end, int idx, int left, int right) {
	// out of bound
	if (end < left || right < start)
		return 0;
	// within bound
	if (left <= start && end <= right)
		return tree[idx];

	int mid = (start + end) / 2;
	return getSum(start, mid, idx * 2, left, right) + getSum(mid + 1, end, idx * 2 + 1, left, right);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> Q;
	int height = ceil(log2(N));
	tree = new ll[1 << (height + 1)];

	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	init(1, N, 1);

	for (int i = 1; i <= Q; i++) {
		int x, y, a;
		ll b;
		cin >> x >> y >> a >> b;
		// x가 y보다 작다는 말은 없었음...
		if (x > y) {
			int temp = y;
			y = x;
			x = temp;
		}
		cout << getSum(1, N, 1, x, y) << '\n';

		ll diff = b - arr[a];
		arr[a] = b;
		updateTree(1, N, 1, a, diff);
	}


	return 0;
}