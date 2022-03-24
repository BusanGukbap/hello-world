#define _CRT_SECURE_NO_WARNINGS

// A.Game

#include <iostream>

using namespace std;

int t, N;
int arr[101];

void input(int x) {
	for (int i = 1; i <= x; i++) {
		cin >> arr[i];
	}
}

void solution(int N) {
	int first = -1, last = -1;

	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) {
			if (first == -1)
				first = i;
			else
				last = i;
		}
	}

	if (first == -1)
		cout << 0 << '\n';
	else if (last == -1)
		cout << 2 << '\n';
	else
		cout << last - first + 2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> N;
		input(N);
		solution(N);

	}
	
	return 0;
}