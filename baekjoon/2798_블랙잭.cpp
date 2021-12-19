#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, M;
int card[101];
int result;
int arr[3];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	result = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}

	int temp = 0;
	for (int i = 1; i <= N - 2; i++) {
		for (int j = i + 1; j <= N - 1; j++) {
			for (int k = j + 1; k <= N; k++) {
				temp = card[i] + card[j] + card[k];
				if (temp > result && temp <= M)
					result = temp;
			}
		}
	}

	cout << result;

	return 0;
}