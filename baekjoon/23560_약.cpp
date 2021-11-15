#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define MAX 15

int N;
bool pill[MAX * 3 + 1];
int cnt;

void func(int index, int front, int back) {
	if (index > 3*N) {
		cnt++;
		return;
	}
	// Á¡½É
	if (index % 3 == 2) {
		// ¾àÀ» ¸ø ¸ÔÀ½ -> Å»Ãâ
		if (!pill[front] && !pill[back]) {
			return;
		}
		// ¾Õ¿¡ ÀÖ´Â ¾à ¸ÔÀ½
		if (pill[front]) {
			func(index + 1, front + 1, back);
		}
		// µÚ¿¡ ÀÖ´Â ¾à ¸ÔÀ½
		if (pill[back]) {
			func(index + 1, front, back - 1);
		}
	}
	// ¾ÆÄ§, Àú³á
	else {
		// ¾àÀ» ¸ø ¸ÔÀ½ -> Å»Ãâ
		if (pill[front] && pill[back]) {
			return;
		}
		// ¾Õ¿¡ ÀÕ´Â ¾à ¸ÔÀ½
		if (!pill[front]) {
			func(index + 1, front + 1, back);
		}
		// µÚ¿¡ ÀÖ´Â ¾à ¸ÔÀ½
		if (!pill[back]) {
			func(index + 1, front, back - 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		pill[i * 3 - 1] = true;
	}
	func(1, 0, 3 * N - 1);

	cout << cnt;

	return 0;
}