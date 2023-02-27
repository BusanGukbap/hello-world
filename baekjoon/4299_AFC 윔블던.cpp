#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	int x = (a + b) / 2;
	int y = (a - b) / 2;
	if (a < b)
		cout << "-1";
	else {
		if (x + y == a && x - y == b)
			cout << x << ' ' << y;
		else
			cout << "-1";
	}


	return 0;
}