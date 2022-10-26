#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int tall[10];
bool check[10];
int cnt;
int total;
int arr[7];

void func(int index) {
	if (arr[0] != 0)
		return;

	if (cnt == 7 && total == 100) {
		int idx = 0;
		for (int i = 0; i < 9; i++) {
			if (check[i] == true) {
				arr[idx++] = tall[i];
			}
		}
	}

	if (index >= 9)
		return;

	for (int i = index; i < 9; i++) {
		check[i] = true;
		total += tall[i];
		cnt++;
		func(i + 1);
		check[i] = false;
		total -= tall[i];
		cnt--;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
		cin >> tall[i];

	func(0);
	sort(arr, arr + 7);
	for (int i = 0; i < 7; i++)
		cout << arr[i] << '\n';

	return 0;
}