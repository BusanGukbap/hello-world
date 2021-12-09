#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

long long N, K;
long long mod = 1000000007;

long long factorial(long long data) {
	long long fac = 1;
	for (int i = 2; i <= data; i++) {
		fac = (fac * i) % mod;
	}
	return fac;
}

long long power(long long base, long long exponent) {
	if (exponent == 1) {
		return base % mod;
	}
	long long temp = power(base, exponent / 2);
	if (exponent % 2 == 1) {
		return(temp * temp % mod) * base % mod;
	}
	return temp * temp % mod;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	long long brother = factorial(N);
	long long mother = factorial(K) * factorial(N-K) % mod;

	cout << brother * power(mother, mod - 2) % mod;

	return 0;
}