#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
vector <int> input_data;
stack <int> S;
int ans;

void input() {
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		input_data.push_back(temp);
	}
}

void solution(int index, int gap, int len) {
	if (index == N) {
		if (ans < len)
			ans = len;
		return;
	}

	for (int i = index; i < N; i++) {
		if (len == 1) {
			gap = S.top() - input_data[i];
			S.push(input_data[i]);
			solution(index + 1, gap, len + 1);
		}
		else {
			if (gap == S.top() - input_data[i]) {
				S.push(input_data[i]);
				solution(index + 1, gap, len + 1);
			}
			else
				S.push(input_data[i]);
		}

		S.pop();
		solution(index + 1, gap, len);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	for (int i = 0; i < N; i++) {
		S.push(input_data[i]);
		solution(i + 1, 0, 1);
		S.pop();
	}

	cout << ans;

	return 0;
}