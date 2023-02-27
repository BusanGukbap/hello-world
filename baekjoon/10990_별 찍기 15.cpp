#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;

	for (int i = 1; i < N; i++)
		cout << ' ';
	cout << "*\n";

	for (int i=1; i<N; i++){
		for (int j = 1; j < N - i; j++)
			cout << ' ';
		cout << '*';
		for (int j = 1; j <= (i - 1) * 2 + 1; j++)
			cout << ' ';
		cout << "*\n";
	}

	return 0;
}