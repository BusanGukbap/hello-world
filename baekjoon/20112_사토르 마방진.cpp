#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
string input[101];

void solution() {
	bool sator = true;
	for (int i = 0; i < N; i++) {
		if (!sator)
			break;
		for (int j = i; j < N; j++) {
			if (!sator)
				break;
			if (input[i][j] != input[j][i])
				sator = false;
		}
	}
	if (sator)
		cout << "YES";
	else
		cout << "NO";
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> input[i];

	solution();

	return 0;
}