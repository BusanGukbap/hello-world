#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define MAX 1025
int N, M;
int board[MAX][MAX];
int X1, X2, Y1, Y2;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	int temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			board[i][j] = board[i][j - 1] + temp;
		}
	}

	int total;
	for (int i = 0; i < M; i++) {
		cin >> X1 >> Y1 >> X2 >> Y2;
		total = 0;

		for (int i = X1; i <= X2; i++) {
			total += board[i][Y2] - board[i][Y1 - 1];
		}
		cout << total << '\n';
	}

	return 0;
}