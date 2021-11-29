#define _CRT_SECURE_NO_WRANINGS

#include <bits/stdc++.h>

using namespace std;

long long T, arr[1000001];
long long input[100001];

void func(int data) {
	for (long long idx = 1; idx <= data; idx++) {
		for (long long j = idx; j <= data; j += idx) {
			arr[j] += idx;
		}
	}
	for (long long idx = 1; idx <= data; idx++) {
		arr[idx] += arr[idx - 1];
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	int maxx = 0;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> input[test_case];
		if (maxx < input[test_case])
			maxx = input[test_case];
	}

	func(maxx);
	for (int t = 0; t < T; t++) {
		cout << arr[input[t]] << '\n';
	}

	return 0;
}