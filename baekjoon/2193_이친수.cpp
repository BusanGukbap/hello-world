#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

//몇번째 자리수, 들어있는 값 
long long int arr[91][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	arr[1][0] = 0; arr[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		arr[i][1] = arr[i - 1][0];
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
	}

	cout << arr[N][0] + arr[N][1];

	return 0;
}