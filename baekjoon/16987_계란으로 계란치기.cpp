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
	// �� ��������
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
			// �տ� ��� �ִ� ����̰ų� ����� �μ������ �Ѿ
			if (i == index)
				continue;
			if (S[i] <= 0)
				continue;
			
			// �տ� �� ������� ��� ������
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