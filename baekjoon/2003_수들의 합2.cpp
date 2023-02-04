#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M;
int input[10001];
int arr[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	cin >> N >> M;
	arr[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
		arr[i] = arr[i - 1] + input[i];
	}

	int cnt = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (arr[j] - arr[i] == M) {
				cnt++;
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}