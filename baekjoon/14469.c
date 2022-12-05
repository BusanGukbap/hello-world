#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SWAP(A, B, temp) {temp=A; A=B; B=temp;}

typedef struct cow {
	int arrive;
	int wait;
}cow;

int main(void) {
	int i, N, j, count = 0, pass = 0;
	scanf("%d", &N);
	
	cow Moo[100];
	cow temp, asdf;

	scanf("%d %d", &Moo[0].arrive, &Moo[0].wait);

	for (i = 1; i < N; i++) {
		scanf("%d %d", &temp.arrive, &temp.wait);
		for (j = 0; j < i; j++) {
			if (Moo[j].arrive > temp.arrive) {
				SWAP(Moo[j], temp, asdf);
			}
		}
		Moo[i].arrive = temp.arrive;
		Moo[i].wait = temp.wait;
	}

	while (pass < N) {
		if (count < Moo[pass].arrive) {
			count = Moo[pass].arrive + Moo[pass].wait;
			pass++;
		}
		else {
			count += Moo[pass].wait;
			pass++;
		}
	}

	printf("%d", count);

	return 0;
}