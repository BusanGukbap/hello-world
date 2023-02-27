#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int arr[1001];

	int cnt = 1, j=0;
	for (int i = 1; i <= 1000; i++) {
		if (j == cnt) {
			cnt++;
			j = 0;
		}
		arr[i] = cnt;
		j++;
	}

	int a, b;
	cin >> a >> b;

	int total = 0;
	for (int i = a; i <= b; i++)
		total += arr[i];

	cout << total << '\n';

	return 0;
}