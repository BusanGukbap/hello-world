#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;

// arr[길이][끝자리숫자]
int arr[101][10];

int solution() {
	if (N == 1)
		return 9;

	for (int i = 1; i < 10; i++)
		arr[1][i] = 1;
	arr[1][0] = 0;
 	
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				arr[i][j] =arr[i - 1][j + 1];
			else if (j == 9)
				arr[i][j] = arr[i - 1][j - 1];
			else
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
		}
	}

	int total = 0;
	for (int i = 0; i < 10; i++) {
		total += arr[N][i];
		total %= 1000000000;
	}

	return total;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	cout << solution();
	
	return 0;
}