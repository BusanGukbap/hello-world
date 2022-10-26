#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;
	double arr[10000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cout << fixed;
	cout.precision(3);
	sort(arr, arr + N);
	for (int i = 0; i < 7; i++) {
		cout << (double)arr[i] << '\n';
	}
	


	return 0;
}