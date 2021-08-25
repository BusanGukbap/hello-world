#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr[42] = { 0, };

	int temp;
	for (int i = 0; i < 10; i++) {
		cin >> temp;
		arr[temp % 42]++;
	}
	int cnt = 0;

	for (int i = 0; i < 42; i++) {
		if (arr[i] != 0)
			cnt++;
	}
	
	cout << cnt;

	return 0;
}