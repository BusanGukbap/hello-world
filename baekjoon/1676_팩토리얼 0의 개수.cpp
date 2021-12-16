#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
int result;

void func(int index) {
	if (N / index == 0)
		return;

	result += N / index;
	func(index * 5);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	func(5);

	cout << result;

	return 0;
}