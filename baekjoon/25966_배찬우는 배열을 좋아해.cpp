#include <bits/stdc++.h>

using namespace std;

int N, M, q;
int arr[3000][3000];
int num[3000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> q;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
		num[i] = i;
	}

	int a, i, j, k;
	while (q--) {
		cin >> a >> i >> j;
		if (a == 0) {
			cin >> k;
			int index = num[i];
			arr[index][j] = k;
		}
		else {
			int temp = num[i];
			num[i] = num[j];
			num[j] = temp;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[num[i]][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}