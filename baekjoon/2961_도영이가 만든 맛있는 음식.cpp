#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
int S[10];		//½Å¸À
int B[10];		//¾´¸À
int result = 1000000000;

void func(int index, int Sour, int Bitterness) {
	if (index == N) {
		return;
	}
	Sour *= S[index];
	Bitterness += B[index];
	result = min(result, abs(Sour - Bitterness));
	func(index + 1, Sour, Bitterness);
	func(index + 1, Sour / S[index], Bitterness - B[index]);

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> B[i];
	}
	
	func(0, 1, 0);

	cout << result;

	return 0;
}