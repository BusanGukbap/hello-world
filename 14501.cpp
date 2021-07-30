#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int result;

int t[17];
int p[17];
int N;

void func(int day, int money) {
	if (day > N) {
		if (money > result)
			result = money;
		return;
	}


	if (t[day] == 1) {
		func(day + 1, money + p[day]);
	}
	else {
		if (day + t[day] <= N+1) {
			func(day + t[day], money + p[day]);
		}
		func(day + 1, money);
	}


}

int main(void) {
	cin >> N;
	result = 0;

	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> p[i];
	}

	func(1, 0);



	cout << result;

	return 0;
}