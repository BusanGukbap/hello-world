#include <bits/stdc++.h>

using namespace std;

int N;
stack<int> S;
queue<char> Q;
int arr[100001];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

bool solution() {
	input();
	int last = 1;

	for (int i = 0; i < N; i++) {
		// push를 해야 하는 경우
		if (last <= arr[i]) {
			while (last <= arr[i]) {
				S.push(last++);
				Q.push('+');
			}

			S.pop();
			Q.push('-');
		}

		// 바로 pop해도 되는 경우
		else if (!S.empty() && S.top() == arr[i]) {
			S.pop();
			Q.push('-');
		}
		else {
			return false;
		}
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (solution()) {
		while (!Q.empty()) {
			cout << Q.front() << "\n";
			Q.pop();
		}
	}
	else
		cout << "NO\n";


	return 0;
}