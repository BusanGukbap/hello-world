#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;

deque<int> dq;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push_back") {
			cin >> temp;
			dq.push_back(temp);
		}
		else if (s == "push_front") {
			cin >> temp;
			dq.push_front(temp);
		}
		else if (s == "pop_front") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (s == "size") {
			cout << dq.size() << '\n';
		}
		else if (s == "empty") {
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "front") {
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.front() << '\n';
		}
		else if (s == "back") {
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.back() << '\n';
		}
	}
	



	return 0;
}