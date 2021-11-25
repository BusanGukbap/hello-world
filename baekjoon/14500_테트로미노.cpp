#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[555][555];

int bigger(int a, int b) {
	return a > b ? a : b;
}

vector<pair<int, int>> tetromino[19];

void make_tetromino() {
	tetromino[0].push_back({ 0, 0 }); tetromino[0].push_back({ 0, 1 }); tetromino[0].push_back({ 1, 0 }); tetromino[0].push_back({ 1, 1 });
	tetromino[1].push_back({ 0, 0 }); tetromino[1].push_back({ 1, 0 }); tetromino[1].push_back({ 2, 0 }); tetromino[1].push_back({ 3, 0 });
	tetromino[2].push_back({ 0, 0 }); tetromino[2].push_back({ 0, 1 }); tetromino[2].push_back({ 0, 2 }); tetromino[2].push_back({ 0, 3 });
	tetromino[3].push_back({ 0, 0 }); tetromino[3].push_back({ 1, 0 }); tetromino[3].push_back({ 2, 0 }); tetromino[3].push_back({ 2, 1 });
	tetromino[4].push_back({ 0, 0 }); tetromino[4].push_back({ 1, 0 }); tetromino[4].push_back({ 0, 1 }); tetromino[4].push_back({ 0, 2 });
	tetromino[5].push_back({ 0, 0 }); tetromino[5].push_back({ 0, 1 }); tetromino[5].push_back({ 1, 1 }); tetromino[5].push_back({ 2, 1 });
	tetromino[6].push_back({ 1, 0 }); tetromino[6].push_back({ 1, 1 }); tetromino[6].push_back({ 1, 2 }); tetromino[6].push_back({ 0, 2 });
	tetromino[7].push_back({ 0, 1 }); tetromino[7].push_back({ 1, 1 }); tetromino[7].push_back({ 2, 1 }); tetromino[7].push_back({ 2, 0 });
	tetromino[8].push_back({ 0, 0 }); tetromino[8].push_back({ 0, 1 }); tetromino[8].push_back({ 0, 2 }); tetromino[8].push_back({ 1, 2 });
	tetromino[9].push_back({ 0, 0 }); tetromino[9].push_back({ 0, 1 }); tetromino[9].push_back({ 1, 0 }); tetromino[9].push_back({ 2, 0 });
	tetromino[10].push_back({ 0, 0 }); tetromino[10].push_back({ 1, 0 }); tetromino[10].push_back({ 1, 1 }); tetromino[10].push_back({ 1, 2 });
	tetromino[11].push_back({ 0, 0 }); tetromino[11].push_back({ 1, 0 }); tetromino[11].push_back({ 1, 1 }); tetromino[11].push_back({ 2, 1 });
	tetromino[12].push_back({ 1, 0 }); tetromino[12].push_back({ 1, 1 }); tetromino[12].push_back({ 0, 1 }); tetromino[12].push_back({ 0, 2 });
	tetromino[13].push_back({ 0, 1 }); tetromino[13].push_back({ 1, 1 }); tetromino[13].push_back({ 1, 0 }); tetromino[13].push_back({ 2, 0 });
	tetromino[14].push_back({ 0, 0 }); tetromino[14].push_back({ 0, 1 }); tetromino[14].push_back({ 1, 1 }); tetromino[14].push_back({ 1, 2 });
	tetromino[15].push_back({ 1, 0 }); tetromino[15].push_back({ 1, 1 }); tetromino[15].push_back({ 1, 2 }); tetromino[15].push_back({ 0, 1 });
	tetromino[16].push_back({ 0, 0 }); tetromino[16].push_back({ 1, 1 }); tetromino[16].push_back({ 1, 0 }); tetromino[16].push_back({ 2, 0 });
	tetromino[17].push_back({ 0, 0 }); tetromino[17].push_back({ 0, 1 }); tetromino[17].push_back({ 0, 2 }); tetromino[17].push_back({ 1, 1 });
	tetromino[18].push_back({ 1, 0 }); tetromino[18].push_back({ 1, 1 }); tetromino[18].push_back({ 0, 1 }); tetromino[18].push_back({ 2, 1 });
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
	make_tetromino();

	int maxx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 19; k++) {
				int total = 0;
				for (int t = 0; t < 4; t++)
					total += arr[i + tetromino[k][t].first][j + tetromino[k][t].second];
				if (maxx < total)
					maxx = total;
			}
		}
	}
	cout << maxx;

	return 0;
}