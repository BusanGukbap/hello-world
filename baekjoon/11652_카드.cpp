#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	long long arr[100001] = { 0 };
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int max = 1;
	long long max_index = arr[0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i - 1] == arr[i]) {
			cnt++;
		}
		else {
			cnt = 1;
		}
		if (max < cnt) {
			max = cnt;
			max_index = arr[i];
		}
	}
	
	cout << max_index;

	return 0;
}