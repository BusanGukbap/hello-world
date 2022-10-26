#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int find_R(int N) {
	int R;
	for (int i = 1; i <= sqrt(N); i++) {
		if (N % i == 0) {
			R = i;
		}
	}
	return R;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str1;
	cin >> str1;

	int R = find_R(str1.length());
	int C = str1.length() / R;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (i + j * R >= str1.length())
				break;
			cout << str1[i + j * R];
		}
	}

	return 0;
}