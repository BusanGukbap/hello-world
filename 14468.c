#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct cow {
	int start;
	int end;
} cow;


int main(void) {
	char str[100];
	scanf("%s", str);
	int i, j, count = 0;
	cow p[26];

	for (i = 0; i < 26; i++) {
		p[i].start = 0;
		p[i].end = 0;
	}

	for (i = 0; i < 52; i++) {
		int index = str[i] - 'A';
		if (p[index].start == 0) 
			p[index].start = i+1;
		else 
			p[index].end = i+1;
	}

	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			int start1 = p[i].start;
			int start2 = p[j].start;
			int end1 = p[i].end;
			int end2 = p[j].end;

			if (start1 < start2 && end1 < end2 && start2 < end1)
				count++;
		}
	}

	printf("%d", count);

	return 0;
}