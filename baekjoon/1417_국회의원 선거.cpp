#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[51];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int cnt = 0;

	while (true) {
		int top_vote = 0, idx = 0;
		for (int i = 1; i <= N; i++) {
			if (top_vote <= arr[i]) {
				top_vote = arr[i];
				idx = i;
			}
		}

		if (idx == 1) {
			break;
		}
		
		cnt++;
		arr[1]++;
		arr[idx]--;
	}
	cout << cnt;

	return 0;
}