#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - i; j++) {
			cout << ' ';
		}
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		cout << '\n';
	}



	return 0;
}