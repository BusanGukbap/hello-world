#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int mapp[100][100];
int N, L, result;
bool bridge[100];

void clear() {
	for (int i = 0; i < N; i++)
		bridge[i] = false;
}

void row(){
	int i, j, cur_height;
	bool road;
	for (i = 0; i < N; i++) {
		cur_height = mapp[i][0];
		road = true;
		clear();

		for (j = 1; j < N; j++) {
			if (road == false)
				break;

			if (mapp[i][j] == cur_height)
				continue;

			// 높낮이 차이가 두칸 이상일 때
			else if (abs(mapp[i][j] - cur_height) > 1) {
				road = false;
				break;
			}
			
			// 내려갈때
			else if (mapp[i][j] - cur_height == -1) {

				int before = mapp[i][j];
				bridge[j] = true;

				for (int k = 1; k < L; k++) {
					if (bridge[j + k] || before != mapp[i][j + k]) {
						road = false;
						break;
					}
					bridge[j + k] = true;
				}

				cur_height = mapp[i][j];
			}

			// 올라갈때
			else if (mapp[i][j] - cur_height == 1) {

				int before = mapp[i][j-1];

				for (int k = 1; k <= L; k++) {
					if (bridge[j - k] || before != mapp[i][j - k]) {
						road = false;
						break;
					}
					bridge[j - k] = true;
				}

				cur_height = mapp[i][j];
			}
		}

		if (road) {
			result++;
		//	cout << "row" << i << '\n';
		}
	}
}

void col() {
	int i, j, cur_height;
	bool road;
	for (i = 0; i < N; i++) {
		cur_height = mapp[0][i];
		road = true;
		clear();

		for (j = 1; j < N; j++) {
			if (road == false)
				break;

			if (mapp[j][i] == cur_height)
				continue;

			// 높낮이 차이가 두칸 이상일 때
			else if (abs(mapp[j][i] - cur_height) > 1) {
				road = false;
				break;
			}

			// 내려갈때
			else if (mapp[j][i] - cur_height == -1) {

				int before = mapp[j][i];
				bridge[j] = true;

				for (int k = 1; k < L; k++) {
					if (bridge[j + k] || before != mapp[j + k][i]) {
						road = false;
						break;
					}
					bridge[j + k] = true;
				}

				cur_height = mapp[j][i];
			}

			// 올라갈때
			else if (mapp[j][i] - cur_height == 1) {

				int before = mapp[j - 1][i];

				for (int k = 1; k <= L; k++) {
					if (bridge[j - k] || before != mapp[j - k][i]) {
						road = false;
						break;
					}
					bridge[j - k] = true;
				}

				cur_height = mapp[j][i];
			}
		}

		if (road) {
			result++;
		//	cout << "col" << i << '\n';
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> mapp[i][j];
	}

	row();
	col();

	cout << result;


	return 0;
}