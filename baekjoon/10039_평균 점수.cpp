#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int total = 0;
	for (int i = 0; i < 5; i++) {
		int a; cin >> a;
		if (a < 40)
			a = 40;
		total += a;
	}

	cout << total / 5;

	return 0;
}