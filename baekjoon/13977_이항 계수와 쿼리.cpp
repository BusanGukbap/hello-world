#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

long long N, K;
long long mod = 1000000007;
long long fac_save[4000001];

void factorial(long long data) {
	fac_save[0] = 1;
	fac_save[1] = 1;
	for (int i = 2; i <= data; i++) {
		fac_save[i] = (fac_save[i-1] * i) % mod;
	}
}

long long fast_power(long long base, long long exponent) {
	long long ret = 1;
	while (exponent) {
		if (exponent & 1) {
			ret = ret * base % mod;
		}
		base = base * base % mod;
		exponent >>= 1;
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	factorial(4000000);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		long long brother = fac_save[N];
		long long mother = fac_save[K] * fac_save[N - K] % mod;
		cout << brother * fast_power(mother, mod - 2) % mod << '\n';
	}

	return 0;
}