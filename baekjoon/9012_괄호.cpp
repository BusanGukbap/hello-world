#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;


int main(void) {
	int test_case;
	cin >> test_case;
	string input;
	int index = 0;
	for (int i = 0; i < test_case; i++) {
		index = 0;
		cin >> input;
		for (int j = 0; j < (int)input.length(); j++) {
			char c = input[j];
			if (c == '(') {
				index++;
			}
			else if (c == ')') {
				index--;
				if (index < 0) {
					cout << "NO" << endl;
					break;
				}
			}

			if (j + 1 == (int)input.length() && index == 0) {
				cout << "YES" << endl;
			}

			else if (j + 1 == (int)input.length() && index != 0) {
				cout << "NO" << endl;
			}
		}

	}
	
	return 0;
}