#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string a; cin >> a;
	int cnt = 0; char c = a[0];
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == c)
			cnt++;
		else
			break;
	}
	cout << cnt;

	return 0;
}