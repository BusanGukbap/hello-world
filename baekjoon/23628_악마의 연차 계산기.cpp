#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int in_year, in_month, in_day;
	int now_year, now_month, now_day;

	cin >> in_year >> in_month >> in_day >> now_year >> now_month >> now_day;

	int day_term = (now_year - in_year) * 12 * 30 + (now_month - in_month) * 30 + (now_day - in_day);
	int month_term = day_term / 30;
	int year_term = day_term / 360;

	int wallchar, kitechar;

	if (month_term > 36) {
		wallchar = 36;
	}
	else
		wallchar = month_term;
	if (year_term == 0)
		kitechar = 0;
	else {
		kitechar = (15)*(year_term);
		int len = 0;
		for (int i = 3; i <= year_term; i++) {
			if (i % 2 == 1)
				len++;
			kitechar += len;
		}
	}

	cout << kitechar << " " << wallchar << '\n';
	cout << day_term << "days";

	return 0;
}