#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long long int power(long long int A, long long int B, long long int C) {
	long long int temp;
	if (B == 0) {
		return 1;
	}
	else if (B % 2 > 0) {
		return power(A, B - 1, C) * A % C;
	}
	else {
		temp = power(A, B / 2, C) % C;
		return (temp * temp) % C;
	}
}

int main(void) {
	long long int A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld", power(A, B, C));
	return 0;
}
