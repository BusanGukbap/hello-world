#include <iostream>

using namespace std;

int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isleap(int year) {
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}

int days(int y, int m, int d) {
	int ans = 0;
	for (int i = 1; i < y; i++) {
		ans += 365;
		if (isleap(i))
			ans++;
	}


	for (int i = 1; i < m; i++) {
		ans += month[i];
		if (i == 2 && isleap(y))
			ans++;
	}

	ans += d;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int y1, y2, m1, m2, d1, d2;
	cin >> y1 >> m1 >> d1;
	cin >> y2 >> m2 >> d2;

	int day = 0;
	int a = days(y1, m1, d1);
	int b = days(y2, m2, d2);
	if (y2 - y1 > 1000 || 
		( (y2-y1 == 1000) && (days(0, m1, d1) <= days(0, m2, d2)) )
		) {
		cout << "gg\n";
		return 0;
	}

//	cout << b << ' ' << a << '\n';
	cout << "D-" << b - a << '\n';

	return 0;
}