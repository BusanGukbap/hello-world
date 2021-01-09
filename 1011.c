#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void Fly_me_to_the_Alpha_Centauri(int x, int y) {
	long long int distance = y - x;
	int count = 1;
	long long int i = 0;

	while (1) {
		i++;
		if (i * i > distance)
			break;
		count += 2;
	}

	if (pow(i - 1, 2) == distance) {
		printf("%d\n", count - 2);
	}
	else if ((pow(i - 1, 2) + pow(i, 2)) / 2 >= distance) {
		printf("%d\n", count - 1);
	}
	else {
		printf("%d\n", count);
	}
}

int main(void) {
	int T, x, y;
	scanf("%d", &T);

	while (T) {
		scanf("%d %d", &x, &y);
		Fly_me_to_the_Alpha_Centauri(x, y);
		T--;
	}

	return 0;
}