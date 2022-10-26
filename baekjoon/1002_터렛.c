#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void turret(int x1, int y1, int r1, int x2, int y2, int r2) {
	double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	int dif = abs(r1 - r2);
	int sum = r1 + r2;
	// 중심이 같을때
	if (distance == 0) {
		if (dif == 0)
			printf("-1\n");
		else
			printf("0\n");
	}
	// 두점이 만날때
	else if (dif < distance && distance < sum) {
		printf("2\n");
	}
	// 외접 & 내접
	else if (dif == distance || sum == distance) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}

int main(void) {
	int T, x1, x2, r1, r2, y1, y2;
	scanf("%d", &T);

	while (T) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		turret(x1, y1, r1, x2, y2, r2);
		T--;
	}

	return 0;
}
