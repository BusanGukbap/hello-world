#include <bits/stdc++.h>

using namespace std;

int N, M;
long long arr1[10000001];
long long arr2[10000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;
		if (temp >= 0)
			arr1[temp]++;
		else
			arr2[-temp]++;
	}

	cin >> M;
	for (int j = 0; j < M; j++) {
		long long temp;
		cin >> temp;
		if (temp >= 0)
			cout << arr1[temp] << " ";
		else
			cout << arr2[-temp] << " ";
	}

	return 0;
}