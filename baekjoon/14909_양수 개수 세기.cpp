#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, cnt = 0;
	while (cin >> a) {
		if (a > 0)
			cnt++;
	}
	cout << cnt;

	return 0;
}