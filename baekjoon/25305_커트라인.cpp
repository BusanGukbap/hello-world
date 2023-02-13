#include <bits/stdc++.h>

using namespace std;

int N, k;
int arr[1010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> k;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N, greater<int>());
	cout << arr[k-1];

	return 0;
}