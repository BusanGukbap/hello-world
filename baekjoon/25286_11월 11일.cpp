#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

// 1 3 5 7 8 10 12월은 31일
// 4 6 9 11 월은 30일
// 2월은 28일, 윤년은 29일

bool leap_year(int y) {
	if (y % 400 == 0)
		return true;
	else if (y % 100 == 0)
		return false;
	else if (y % 4 == 0)
		return true;
	return false;
}

void solution() {
	int year, month, day;
	cin >> year >> month;
	bool leap = leap_year(year);

	month--;
	if (month == 0) {
		month = 12;
		year--;
	}

	if (month == 2) {
		if (leap)
			day = 29;
		else
			day = 28;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		day = 31;
	}
	else {
		day = 30;
	}
	cout << year << " " << month << " " << day << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		solution();
	}

	return 0;
}