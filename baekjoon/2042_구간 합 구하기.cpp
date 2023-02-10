#include <bits/stdc++.h>

using namespace std;

int N, M, K;
long long int arr[1000002];
long long int tree[4000002];

long long int makeTree(int start, int end, int Idx) {
	if (start == end)
		return tree[Idx] = arr[start];
	int mid = (start + end) / 2;

	return tree[Idx] = makeTree(start, mid, Idx * 2) + makeTree(mid + 1, end, Idx * 2 + 1);
}

// left~right���� ���� ����
long long int getSum(int start, int end, int idx, int left, int right) {
	// ������ ��� ���
	if (left > end || right < start)
		return 0;
	// ���� �ȿ� �ִ� ��� -> ���� ��带 ��ȯ
	if (left <= start && end <= right)
		return tree[idx];

	// ���� �Ȱ� ���� ���� �ִ� ��� -> ������
	int mid = (start + end) / 2;
	return getSum(start, mid, idx * 2, left, right) + getSum(mid + 1, end, idx * 2 + 1, left, right);
}

void update(int start, int end, int idx, int changeNode, long long int changeData) {
	// ������ ��� ���
	if (changeNode < start || changeNode > end)
		return;

	// ���� �ȿ� ������ �������� ��尪 ����
	long long int temp = changeData - arr[changeNode];

	tree[idx] += temp;
	if (start == end)
		return;

	int mid = (start + end) / 2;
	update(start, mid, idx * 2, changeNode, changeData);
	update(mid + 1, end, idx * 2 + 1, changeNode, changeData);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	makeTree(1, N, 1);
	
	int a, b;
	long long int c;
	for (int i = 0; i < M+K; i++) {
		cin >> a >> b >> c;
		
		// change number b��° ���� c�� �ٲ�
		if (a == 1) {
			update(1, N, 1, b, c);
			arr[b] = c;
		}

		// get sum b��°���� c��°������ ��
		else if (a == 2) {
			cout << getSum(1, N, 1, b, c) << '\n';
		}
	}

	return 0;
}