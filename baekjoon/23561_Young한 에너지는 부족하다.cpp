#define CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
vector <int> arr;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1; i <= 3*N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	cout << arr[2 * N - 1] - arr[N];

	return 0;
}