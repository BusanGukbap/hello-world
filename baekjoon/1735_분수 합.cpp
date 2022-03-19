#include <bits/stdc++.h>

using namespace std;

int A1, B1, A2, B2;

int Greatest_Common_Divisor(long long int x, long long int y) {
	long long int ans;
	
	long long int temp;
	if (y > x) {
		temp = x;
		x = y;
		y = temp;
	}

	while (x % y != 0) {
		temp = x % y;
		x = y;
		y = temp;
	}

	ans = y;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A1 >> B1;
	cin >> A2 >> B2;
	
	long long int X, Y;
	Y = B1 * B2;
	X = A1 * B2 + A2 * B1;

	int GCD = Greatest_Common_Divisor(X, Y);
	X /= GCD;
	Y /= GCD;

	cout << X << " " << Y;

	return 0;
}