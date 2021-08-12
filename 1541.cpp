#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	string temp = "";
	int res = 0;
	bool m = false;
	for (int i = 0; i <= S.length(); i++) {
		if (S[i] == '+' || S[i] == '-' || S[i] == '\0') {
			if (m) {
				res -= stoi(temp);
			}
			else
				res += stoi(temp);

			if (S[i] == '-') {
				m = true;
			}
			temp = "";
		}
		else
			temp += S[i];
	}

	cout << res;
	
	return 0;
}