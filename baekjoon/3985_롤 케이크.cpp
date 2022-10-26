#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int L, N;
bool arr[1001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> N;
	int max_want = 0, max_take = 0, max_want_index, max_take_index;
	int a, b, cnt;

	for (int i = 1; i <= N; i++) {
		cnt = 0;
		cin >> a >> b;
		if (max_want < b - a + 1) {
			max_want = b - a + 1;
			max_want_index = i;
		}
		for (int j = a; j <= b; j++) {
			if (arr[j] == false) {
				cnt++;
				arr[j] = true;
			}
			if (max_take < cnt) {
				max_take = cnt;
				max_take_index = i;
			}
		}
	}
	cout << max_want_index << '\n' << max_take_index;

	return 0;
}