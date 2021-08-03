#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char input[16];
char save[16];

int aeiou() {
	for (int i = 0; i < L; i++) {
		if (save[i] == 'a' || save[i] == 'e' || save[i] == 'i' || save[i] == 'o' || save[i] == 'u')
			return 1;
	}
	return 0;
}

int vowel() {
	int temp = 0;
	for (int i = 0; i < L; i++) {
		if (save[i] != 'a' && save[i] != 'e' && save[i] != 'i' && save[i] != 'o' && save[i] != 'u')
			temp++;
	}
	if (temp >= 2) {
		return 1;
	}
	else
		return 0;
}

void func(int index) {
	if (index == L) {
		if (aeiou() && vowel()) {
			for (int i = 0; i < L; i++) {
				cout << save[i];
			}
			cout << '\n';
		}
	}

	for (int i = 0; i < C; i++) {
		if (index == 0 || (save[index - 1] < input[i])) {
			save[index] = input[i];
			func(index + 1);
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> input[i];
	}
	sort(input, input + C);
	
	func(0);



	return 0;
}