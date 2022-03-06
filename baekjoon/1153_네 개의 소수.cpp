#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;

bool IsPrimeNum (int x){
	if (x < 2)
		return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	if (N != 8 && N < 9)
		cout << -1;
	else {
		if (N % 2) {
			cout << "2 3 ";
			N -= 5;
		}
		else {
			cout << "2 2 ";
			N -= 4;
		}
		if (N == 4)
			cout << "2 2 ";
		else
			// 골드바흐의 강한추측, 10^18까지는 true
			for (int i = 3; i < N; i+=2) {
				if (IsPrimeNum(i) && IsPrimeNum(N - i)) {
					cout << i << ' ' << N - i;
					break;
				}
			}
	}

	return 0;
}