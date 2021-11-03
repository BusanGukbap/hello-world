#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string input;
	queue <int> Q;
	cin >> N;
	while (N--) {
		cin >> input;
		if (input == "push") {
			int temp;
			cin >> temp;
			Q.push(temp);
		}

		else if (input == "pop") {
			if (Q.empty())
				cout << -1 << '\n';
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}

		else if (input == "size")
			cout << Q.size() << '\n';

		else if (input == "empty") {
			if (Q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}

		else if (input == "front") {
			if (Q.empty())
				cout << -1 << '\n';
			else
				cout << Q.front() << '\n';
		}

		else if (input == "back") {
			if (Q.empty())
				cout << -1 << '\n';
			else
				cout << Q.back() << '\n';
		}
	}

	return 0;
}