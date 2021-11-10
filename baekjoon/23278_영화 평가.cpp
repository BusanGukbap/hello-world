#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, L, H;
int arr[50];

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> L >> H;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	double total = 0;
	for (int i = L; i < N - H; i++) {
		total += (double)arr[i];
	}
	total /= (double)(N - L - H);
	
	cout << fixed;
	cout.precision(11);
	cout << total;

	return 0;
}