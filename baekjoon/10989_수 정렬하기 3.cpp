#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[10001] = { 0 };
	int N, temp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[temp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++)
			cout << i << "\n";
	}

	return 0;
}