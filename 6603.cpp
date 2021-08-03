#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int input;
int arr[13];
int save[13];

int visit(int data, int index) {
	for (int i = 0; i < index; i++) {
		if (save[i] == data) {
			return 0;
		}
	}
	return 1;
}

void func(int index) {
	if (index == 6) {
		for (int i = 0; i < 6; i++) {
			cout << save[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < input; i++) {
		if (index == 0 || (visit(arr[i], index) && arr[i] > save[index-1])) {
			save[index] = arr[i];
			func(index + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> input;
		if (input == 0) {
			break;
		}

		for (int i = 0; i < input; i++) {
			cin >> arr[i];
		}
		func(0);
		cout << '\n';
	}

	return 0;
}