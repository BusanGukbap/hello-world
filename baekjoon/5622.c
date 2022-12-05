#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void) {
	int i, a[26], count = 0;
	a[0] = a[1] = a[2] = 3;
	a[3] = a[4] = a[5] = 4;
	a[6] = a[7] = a[8] = 5;
	a[9] = a[10] = a[11] = 6;
	a[12] = a[13] = a[14] = 7;
	a[15] = a[16] = a[17] = a[18] = 8;
	a[19] = a[20] = a[21] = 9;
	a[22] = a[23] = a[24] = a[25] = 10;

	char str[20];
	scanf("%s", str);
	for (i = 0; i < strlen(str); i++) {
		count += a[str[i] - 'A'];
	}
	printf("%d", count);
}