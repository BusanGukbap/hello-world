#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int N;

void input() {
	arr.clear();
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
}

void solution() {
	input();
	int cnt = 1;
	double standard = (double)(N+1) / 2;
	int before, bigger, smaller;
	
	if ((double)arr[0] <= standard) {
		before = arr[0];
	}
	else
		before = N - arr[0] + 1;

	for (int i = 1; i < N; i++) {
		if ((double)arr[i] > standard) {
			bigger = arr[i];
			smaller = N - arr[i] + 1;
		}
		else {
			bigger = N - arr[i] + 1;
			smaller = arr[i];
		}

		if (before <= smaller) {
			cnt++;
			before = smaller;
		}
		else if (before > smaller && before <= bigger) {
			before = bigger;
			cnt++;
		}
		else if (before > bigger)
			break;
	}

	if (cnt == N) {
		cout << "YES\n";
	}
	else
		cout << "NO\n";

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solution();


	return 0;
}