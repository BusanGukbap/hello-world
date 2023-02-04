#include <bits/stdc++.h>

using namespace std;
	
int N, M;
int tK, tD, tA;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		
		long long int K[100], D[100], A[100];
		for (int i = 0; i < M; i++) {
			cin >> K[i] >> D[i] >> A[i];
		}

		int k, d, a;
		long long int total = 0;
		cin >> k >> d >> a;
		for (int i = 0; i < M; i++) {
			long long int T = K[i] * k + a * A[i] - D[i] * d;
			if (T < 0)
				continue;
			total += T;
		}

		cout << total << '\n';
	}

	return 0;
}