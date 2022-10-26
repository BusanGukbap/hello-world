#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int map[1001][1001];


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int len = 0;
	string input;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		for (int j = 1; j <= m; j++)
			map[i][j] = input[j-1] - '0';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != 0) {
				map[i][j] = min(map[i - 1][j - 1], min(map[i][j - 1], map[i - 1][j])) + 1;
				len = max(len, map[i][j]);
			}
		}
	}

	cout << len * len;

	return 0;
}