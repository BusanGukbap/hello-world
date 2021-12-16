#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T, A, B;
	cin >> T;
	
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> A >> B;
		cout << A + B << '\n';
	}

	return 0;
}
