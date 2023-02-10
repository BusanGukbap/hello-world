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

// left~right까지 범위 구함
long long int getSum(int start, int end, int idx, int left, int right) {
	// 범위를 벗어난 경우
	if (left > end || right < start)
		return 0;
	// 범위 안에 있는 경우 -> 현재 노드를 반환
	if (left <= start && end <= right)
		return tree[idx];

	// 범위 안과 밖이 같이 있는 경우 -> 나눠줌
	int mid = (start + end) / 2;
	return getSum(start, mid, idx * 2, left, right) + getSum(mid + 1, end, idx * 2 + 1, left, right);
}

void update(int start, int end, int idx, int changeNode, long long int changeData) {
	// 범위를 벗어난 경우
	if (changeNode < start || changeNode > end)
		return;

	// 범위 안에 있으면 내려가며 노드값 갱신
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
		
		// change number b번째 수를 c로 바꿈
		if (a == 1) {
			update(1, N, 1, b, c);
			arr[b] = c;
		}

		// get sum b번째부터 c번째까지의 합
		else if (a == 2) {
			cout << getSum(1, N, 1, b, c) << '\n';
		}
	}

	return 0;
}