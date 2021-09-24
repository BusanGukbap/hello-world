#define _CRT_SECURE_NO_WARNINGS
// SW Expert Academy
// 12004 ±¸±¸´Ü 1 , D3

#include <iostream>

using namespace std;

int main(void) {
	int N, temp;
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp > 81) {
			cout << "#" << i + 1 << " No" << endl;
		}
		else {
			for (a = 1; a <= 9; a++) {
				if (temp % a == 0 && ((temp / a) <= 9 && (temp / a) >= 1)) {
					cout << "#" << i + 1 << " Yes" << endl;
					break;
				}
			}
			if (a == 10) {
				cout << "#" << i + 1 << " No" << endl;
			}
		}
	}


	return 0;
}