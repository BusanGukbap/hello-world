#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, S;
int result;
int input[21];

void func(int total, int index) {
	if (index > N) {
		return;
	}
	
	if (total == 1000001) {
		if (input[index] == S) {
			result += 1;
		}
		func(input[index], index + 1);
		func(total, index + 1);
	}
	else {
		if (total+input[index] == S) {
			result += 1;
		}
		func(total + input[index], index+1);
		func(total, index + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 1; i <= N; i++)
		cin >> input[i];
	result = 0;

	func(1000001, 1);

	cout << result;

	return 0;
}