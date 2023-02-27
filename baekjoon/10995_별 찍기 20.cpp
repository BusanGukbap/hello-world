#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2*N; j++) {
			if (i % 2 == 1) {
				if (j % 2 == 1)
					cout << '*';
				else
					cout << ' ';
			}
			else {
				if (j % 2 == 1)
					cout << ' ';
				else
					cout << '*';
			}
		}
		cout << '\n';
	}

	return 0;
}