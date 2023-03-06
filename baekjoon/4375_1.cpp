#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; 
	while (cin >> n) {
		int ans = 1;
		int temp = 1;
		while (1) {
			if (temp % n == 0)
				break;
			else {
				ans++;
				temp *= 10;
				temp += 1;
				temp %= n;
			}
		}

		cout << ans << '\n';
	}


	return 0;
}