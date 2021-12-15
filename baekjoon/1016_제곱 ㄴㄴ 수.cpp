#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

long long int N, M;
bool arr[1000010];

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (long long int i = 2; i * i <= M; i++) {
		long long int temp = (N / (i * i)) * (i * i);
		while (temp <= M) {
			if (temp >= N)
				arr[temp - N] = true;
			temp += (i * i);
		}
	}

	int total = 0;
	for (int i = 0; i <= M - N; i++) {
		if (!arr[i])
			total++;
	}

	cout << total;

	return 0;
}