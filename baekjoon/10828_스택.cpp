#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	string str;
	int temp;

	int stack[10001];
	int top = -1;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> temp;
			stack[++top] = temp;
		}
		else if (str == "pop") {
			if (top == -1) {
				cout << -1 << "\n";
			}
			else {
				cout << stack[top--] << "\n";
			}
		}
		else if (str == "size") {
			cout << top+1 << "\n";
		}
		else if (str == "empty") {
			if (top == -1) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (str == "top") {
			if (top == -1) {
				cout << -1 << "\n";
			}
			else {
				cout << stack[top] << "\n";
			}
		}
	}

	return 0;
}