#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100][100], temp;
	int n, i, j, arr[26], count = 0;
	scanf("%d ", &n);

	for (i = 0; i < n; i++){
		scanf("%s", str[i]);
		for (j = 0; j < 26; j++)
			arr[j] = 0;
		temp = str[i][0];
		arr[str[i][0] - 'a']++;

		for (j = 1; j < strlen(str[i]); j++) {
			if ((temp != str[i][j]) && arr[str[i][j]-'a']>0) {
				count--;
				break;
			}
			temp = str[i][j];
			arr[str[i][j] - 'a']++;
		}
		count++;
	}
	printf("%d", count);
	return 0;
}