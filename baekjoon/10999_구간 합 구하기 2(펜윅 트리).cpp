#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// P[i] = arr[1] + arr[2] + ... + arr[i]
// ΔP[i] = (diff) * i - diff * (left - 1) [a <= x <= b]
// ΔP[i] = (diff) * 0 - diff * (- right + left - 1) [b < x]
// P[i] = (tree1[i]의 비트구간합) * i - (tree2[i]의 비트구간합)
int N, M, K;
ll tree1[1000001];
ll tree2[1000001];

void update(int treeBit, int idx, ll diff) {
	ll* tree = (treeBit == 1) ? tree1 : tree2;
	while (idx <= N) {
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

void rangeUpdate(int left, int right, ll diff) {
	// tree1[left] += diff, tree1[right+1] -= diff
	update(1, left, diff);
	update(1, right + 1, -diff);
	// tree2[left] += diff*(left-1), tree2[right + 1] -= diff*(left-1)
	// tree2[right + 1] += diff*(- right + left - 1) 위의 tree2[right + 1]과 합치면
	// tree2[right + 1] += diff*(-right)
	update(2, left, diff * (left - 1));
	update(2, right + 1, -diff * right);
}

ll sum(int idx) {
	int pos = idx;
	ll a = 0, b = 0;
	while (idx > 0) {
		a += tree1[idx];
		b += tree2[idx];
		idx -= idx & -idx;
	}

	return a * pos - b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		rangeUpdate(i, i, a);
	}

	for (int t = 1; t <= (M + K); t++) {
		int a, b, c; ll d;
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			rangeUpdate(b, c, d);
		}
		else if (a == 2) {
			cout << sum(c) - sum(b - 1) << '\n';
		}
	}


	return 0;
}