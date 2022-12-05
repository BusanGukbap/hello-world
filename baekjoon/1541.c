#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	char str[100];
	scanf("%s", str);
	int i;
	int nuclear = 0; // +들을 모으는 곳
	int temp = 0;	// 숫자 측정
	int result = 0; // 결과값
	int first_number = 1;
	int minus = 0;

	for (i = 0; i <= strlen(str); i++) {
		if (str[i] == '+' || str[i] == '-') {
			if (first_number == 1) {
				result += temp;
				temp = 0;
				first_number = 0;
			}
			if (minus == 0) {
				result += temp;
				temp = 0;
				if (str[i] == '-')
					minus++;
			}
			else if (minus != 0) {
				nuclear += temp;
				temp = 0;
				if (str[i] == '-') {
					result -= nuclear;
					nuclear = 0;
				}
			}
		}

		// 숫자일때
		else if (str[i]<= '9' && str[i]>= '0'){
			temp *= 10;
			temp += str[i] - '0';
		}

		else {
			if (minus == 0) {
				result += temp;
			}
			else if (minus != 0) {
				nuclear += temp;
				result -= nuclear;
			}
		}
	}

	printf("%d", result);

	return 0;
}