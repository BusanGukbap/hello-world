#include <bits/stdc++.h>

using namespace std;

int N, K, result;
bool alphabet[26];
string input[50];

void solve() {
	int cnt = 0, i, j;
	for (i = 0; i < N; i++) {
		for (j = 4; j < input[i].size(); j++) {
			if (alphabet[input[i][j] - 'a'] == false)
				break;
		}
		if (j == input[i].size())
			cnt++;
	}
	if (cnt > result)
		result = cnt;
}

void backtracking(int index, int start) {
	if (index > K) {
		return;
	}
	if (index == K) {
		solve();
		return;
	}
	
	for (int i = start; i < 26; i++) {
		if (alphabet[i] == false) {
			alphabet[i] = true;
			backtracking(index + 1, i + 1);
			alphabet[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	alphabet['a' - 'a'] = true; alphabet['n' - 'a'] = true; alphabet['t' - 'a'] = true; alphabet['i' - 'a'] = true; alphabet['c' - 'a'] = true;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	backtracking(5, 0);

	cout << result;

	return 0;
}