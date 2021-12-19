#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int save[8];

void func(int index) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << save[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (index == 0 || (save[index - 1] <= arr[i])) {
			save[index] = arr[i];
			func(index + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	func(0);

	return 0;
}