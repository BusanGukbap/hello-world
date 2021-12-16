#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

string str;
queue<int> q;

int box[1000][1000];

void func(int input) {
	string str;
	int temp;
	for (int i = 0; i < input; i++) {
		cin >> str;
		if (str == "push") {
			cin >> temp;
			q.push(temp);
		}

		else if (str == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				temp = q.front();
				q.pop();
				cout << temp << '\n';
			}
		}

		else if (str == "size") {
			cout << q.size() << '\n';
		}
		
		else if (str == "empty") {
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}

		else if (str == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}

		else if (str == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	func(N);

	return 0;
}