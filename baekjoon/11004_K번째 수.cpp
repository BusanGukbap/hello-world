#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	
	cin >> N >> K;
	int* arr = new int[N];
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(&arr[0], &arr[N]);
	
	cout << arr[K - 1];

	return 0;
}