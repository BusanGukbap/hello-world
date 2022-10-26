#include<bits/stdc++.h>

using namespace std;

int N, answer;
int S[9];
int W[9];
int egg;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> S[i] >> W[i];
	}
}

void backtracking(int index) {
	// 다 돌았을때
	if (index > N) {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (S[i] <= 0)
				cnt++;
		}

		if (cnt > answer)
			answer = cnt;
		return;
	}

	if (S[index] <= 0) {
		backtracking(index + 1);
	}

	else {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			// 손에 들고 있는 계란이거나 계란이 부서진경우 넘어감
			if (i == index)
				continue;
			if (S[i] <= 0)
				continue;
			
			// 손에 든 계란으로 계란 때리기
			S[index] -= W[i];
			S[i] -= W[index];
			cnt++;
			backtracking(index + 1);
			S[index] += W[i];
			S[i] += W[index];
		}

		if (cnt == 0)
			backtracking(index + 1);
	}
}

void solution() {
	input();
	backtracking(1);
	cout << answer << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	solution();

	return 0;
}