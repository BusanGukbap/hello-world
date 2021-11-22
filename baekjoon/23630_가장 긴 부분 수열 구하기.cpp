#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
int input[1000001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int maxx = 0;

	for (int i = 1; i <= N; i++) {
		cin >> input[i];
		if (maxx < input[i])
			maxx = input[i];
	}

	int result = 0;
	for (int i = 1; i <= maxx; i = i << 1) {
		int cnt = 0;
		for (int j = 1; j <= N; j++)
			if (input[j] & i)
				cnt++;
		if (cnt > result)
			result = cnt;
	}
	cout << result;

	return 0;
}