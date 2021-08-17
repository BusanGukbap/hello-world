#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, M;
char map[50][50];
int col[50];
int row[50];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'X') {
				col[i]++;
				row[j]++;
			}
		}
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < N; i++) {
		if (col[i] == 0)
			cnt1++;
	}
	for (int j = 0; j < M; j++) {
		if (row[j] == 0)
			cnt2++;
	}
	if (cnt1 > cnt2)
		cout << cnt1;
	else
		cout << cnt2;

	return 0;
}