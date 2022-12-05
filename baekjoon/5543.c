#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int a, b, Top_Buger, Mid_Buger, Bot_Buger, Coke, Sprite;
	scanf("%d %d %d %d %d", &Top_Buger, &Mid_Buger, &Bot_Buger, &Coke, &Sprite);
	(Coke > Sprite) ? (a = Sprite) : (a = Coke);
	if (Top_Buger > Mid_Buger)
		(Mid_Buger > Bot_Buger) ? (b = Bot_Buger) : (b = Mid_Buger);
	else
		(Top_Buger > Bot_Buger) ? (b = Bot_Buger) : (b = Top_Buger);
	printf("%d", a + b - 50);
	return 0;
}
