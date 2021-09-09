#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M, B;
int arr[500][500];
bool height[257];

int bruth_force(int index) {
	int total = 0;
	int block = B;
	int temp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp = arr[i][j] - index;
			block += temp;

			// 블록을 제거 한경우
			if (temp > 0)
				total += temp * 2;
			// 블록을 놓은 경우
			else
				total += abs(temp);
		}
	}
	if (block < 0) {
		return -1;
	}

	return total;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			height[arr[i][j]] = true;
		}
	}

	int res = -1;
	int temp = 0, zzzzz = 0;
	for (int i = 0; i <= 256; i++) {
		temp = bruth_force(i);
		if (temp != -1) {
			if (res == -1)
				res = temp;

			if (temp <= res) {
				res = temp;
				zzzzz = i;
			}
		}
	}

	cout << res << " " << zzzzz;

	return 0;
}