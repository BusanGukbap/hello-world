#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int A, B, C, N;
int gori[1000];

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A >> B >> C >> N;

	int a, b, c;
	int top = 0;
	for (int i = 0; i < N; i++) {
		gori[i] = 0;
		for (int people = 0; people < 3; people++) {
			cin >> a >> b >> c;
			gori[i] += a * A + b * B + c * C;
		}
		if (top < gori[i])
			top = gori[i];
	}
	cout << top;

	return 0;
}