#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

stack<char> S;

void func(string input) {
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '*' || input[i] == '/') {
			while (!S.empty() && ( S.top() == '*' || S.top() == '/' )) {
				cout << S.top();
				S.pop();
			}
			S.push(input[i]);
		}
		else if (input[i] == '+' || input[i] == '-') {
			while (!S.empty()) {
				if (S.top() == '(')
					break;
				cout << S.top();
				S.pop();
			}
			S.push(input[i]);
		}
		else if (input[i] == '(') {
			S.push(input[i]);
		}
		else if (input[i] == ')') {
			while (S.top() != '(') {
				cout << S.top();
				S.pop();
			}
			S.pop();
		}
		else {
			cout << input[i];
		}
	}
	while (!S.empty()) {
		cout << S.top();
		S.pop();
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string input;
	cin >> input;
	func(input);

	return 0;
}