#include <iostream>

using namespace std;

int N, S;
int arr[100000];
int total[100000];
int ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (i == 1) {
			total[i] = arr[i];
			continue;
		}
		total[i] = arr[i] + total[i - 1];
	}
	total[0] = 0;
	
	ans = N+1;
	int first = 0, second = 0;

	while (first <= N) {
		int temp = total[first] - total[second];
		if (temp < S) {
			first++;
			continue;
		}
		
		if (first - second < ans) {
			ans = first - second;
		}

		second++;
	}
	

	if (ans > N) {
		cout << 0;
	}
	else
		cout << ans;

	return 0;
}