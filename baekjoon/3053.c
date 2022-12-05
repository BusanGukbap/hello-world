#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void) {
	double R;
	scanf("%lf", &R);

	printf("%lf\n%lf", R * R * M_PI, R * R * 2);


	return 0;
}