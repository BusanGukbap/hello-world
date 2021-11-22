#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int T, N, K;
char dir;

void func() {
	int total = 0;
	for (int i = 1; ; i++) {
		total += i * K;

		if (total >= N) {
			total -= i * K;
			int gap = N - total - 1;
			int now = (i)/2 * K;


			if (i % 2 == 1) {
				now *= -1;
				now += gap;
				dir = 'R';
			}
			else {
				now -= gap;
				dir = 'L';
			}




			cout << now << " " << dir << '\n';
			return;
		}
	}
	
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> K;
		func();
	}


	return 0;
}