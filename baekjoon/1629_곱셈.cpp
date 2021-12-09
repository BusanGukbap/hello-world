#include <iostream>

using namespace std;

long long A, B, C;

long long cal(int index) {
	if (index == 1)
		return A % C;
	long long temp;
	temp = cal(index / 2);
	if (index % 2 == 1) {
		return temp * temp % C * A % C;
	}
	else if (index % 2 == 0) {
		return temp * temp % C;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> A >> B >> C;

	cout << cal(B);

	return 0;
}