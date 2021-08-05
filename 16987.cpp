#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N;
int result;
int S[9];
int W[9];

void func(int index) {
	if (index > N) {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (S[i] <= 0)
				cnt++;
		}
		if (cnt > result) 
			result = cnt;
		
		return;
	}

	if (S[index] <= 0)
		func(index + 1);

	else {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (S[i] > 0 && index != i) {
				S[i] -= W[index];
				S[index] -= W[i];
				cnt++;
				func(index + 1);
				S[i] += W[index];
				S[index] += W[i];
			}
		}
		if (cnt == 0) {
			func(N + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	result = 0;
	for (int i = 1; i <= N; i++) {
		cin >> S[i] >> W[i];
	}

	func(1);

	cout << result;


	return 0;
}