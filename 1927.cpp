#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, temp;
	cin >> N;

	priority_queue<int> q;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == 0) {
			if (q.empty())
				cout << "0\n";
			else {
				cout << (-1) * q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(-temp);
		}
	}


	return 0;
}