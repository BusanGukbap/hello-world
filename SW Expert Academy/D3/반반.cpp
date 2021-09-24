#define _CRT_SECURE_NO_WARNINGS
// SW Expert Academy
// 11856 ¹Ý¹Ý, D3

#include <iostream>

using namespace std;

int main(void) {
	int TC;
	cin >> TC;
	string S;
	int first, second, first_count, second_count;

	for (int i = 1; i <= TC; i++) {
		cin >> S;
		first_count = 1;
		second_count = 0;
		first = S[0] - 'A';

		for (int j = 1; j < 4; j++) {
			if (first == S[j] - 'A') {
				first_count++;
				if (first_count > 2) {
					cout << "#" << i << " No" << endl;
					break;
				}
			}
			else if (second_count == 0) {
				second = S[j] - 'A';
				second_count++;
			}
			else if (second == S[j] - 'A') {
				second_count++;
				if (second_count > 2) {
					cout << "#" << i << " No" << endl;
					break;
				}
			}
			else {
				cout << "#" << i << " No" << endl;
				break;
			}
		}
		if (second_count == 2 && first_count == 2) {
			cout << "#" << i << " Yes" << endl;
		}
	}


	return 0;
}