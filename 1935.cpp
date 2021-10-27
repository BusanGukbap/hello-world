#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

string input;
int N;
double arr[26];
stack <double> S;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> input;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '*') {
			double temp = S.top();
			S.pop();
			S.top() = (double)S.top() * temp;
		}
		else if (input[i] == '-') {
			double temp = S.top();
			S.pop();
			S.top() = (double)S.top() - temp;
		}
		else if (input[i] == '+') {
			double temp = S.top();
			S.pop();
			S.top() = (double)S.top() + temp;
		}
		else if (input[i] == '/') {
			double temp = S.top();
			S.pop();
			S.top() = (double)S.top() / temp;
		}
		else {
			int temp = input[i] - 'A';
			S.push(arr[temp]);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << S.top();

	return 0;
}