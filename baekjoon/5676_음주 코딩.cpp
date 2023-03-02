#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef struct node {
	bool isZero = false;
	int minusCnt = 0;
} Node;

int N, K;
int X[100001];
Node *tree;
queue<char> q;

Node init(int start, int end, int idx) {
	if (start == end) {
		if (X[start] == 0) {
			tree[idx].isZero = true;
			tree[idx].minusCnt = 0;
		}
		else if (X[start] > 0) {
			tree[idx].isZero = false;
			tree[idx].minusCnt = 0;
		}
		else if (X[start] < 0) {
			tree[idx].isZero = false;
			tree[idx].minusCnt = 1;
		}

		return tree[idx];
	}

	int mid = (start + end) / 2;
	Node temp1 = init(start, mid, idx * 2);
	Node temp2 = init(mid + 1, end, idx * 2 + 1);

	tree[idx].isZero = temp1.isZero || temp2.isZero;
	tree[idx].minusCnt = temp1.minusCnt + temp2.minusCnt;

	return tree[idx];
}

Node funcP(int start, int end, int idx, int left, int right) {
	// out of bound
	if (end < left || right < start) {
		Node temp;
		temp.isZero = false;
		temp.minusCnt = 0;
		return temp;
	}
	// within bound
	if (left <= start && end <= right) {
		return tree[idx];
	}

	int mid = (start + end) / 2;
	Node temp1 = funcP(start, mid, idx * 2, left, right);
	Node temp2 = funcP(mid + 1, end, idx * 2 + 1, left, right);
	Node temp3;
	temp3.isZero = temp1.isZero || temp2.isZero;
	temp3.minusCnt = temp1.minusCnt + temp2.minusCnt;
	return temp3;
}

void update(int idx) {
	while (idx) {
		tree[idx].isZero = tree[idx * 2].isZero || tree[idx * 2 + 1].isZero;
		tree[idx].minusCnt = tree[idx * 2].minusCnt + tree[idx * 2 + 1].minusCnt;
		idx /= 2;
	}
}

void nodeUpdate(int start, int end, int idx, int target, int diff) {
	if (start == end) {
		X[start] = diff;

		if (diff == 0) {
			tree[idx].isZero = true;
			tree[idx].minusCnt = 0;
		}
		else {
			tree[idx].isZero = false;
			if (diff < 0)
				tree[idx].minusCnt = 1;
			else
				tree[idx].minusCnt = 0;
		}
		update(idx / 2);
		return;
	}

	int mid = (start + end) / 2;
	if (target <= mid)
		nodeUpdate(start, mid, idx * 2, target, diff);
	else
		nodeUpdate(mid + 1, end, idx * 2 + 1, target, diff);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (cin >> N >> K) {
		int height = ceil(log2(N));
		tree = new Node[1 << (1 + height)];

		for (int i = 1; i <= N; i++)
			cin >> X[i];

		init(1, N, 1);

		char c; int a, b;
		for (int i = 1; i <= K; i++) {
			cin >> c >> a >> b;
			// X[a] = b로 바꾸기
			if (c == 'C') {
				nodeUpdate(1, N, 1, a, b);
			}
			// [a, b]의 곱이 -, +, 0 구분 출력
			else if (c == 'P') {
				Node temp = funcP(1, N, 1, a, b);
				if (temp.isZero)
					q.push('0');
				else {
					if (temp.minusCnt % 2 == 0)
						q.push('+');
					else
						q.push('-');
				}
			}
		}

		while (!q.empty()) {
			cout << q.front();
			q.pop();
		}
		cout << '\n';
	}

	return 0;
}