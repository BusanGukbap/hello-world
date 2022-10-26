#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
int Alphabet[26];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		if (S[i] >= 'a' && S[i] <= 'z') {
			Alphabet[S[i] - 'a']++;
		}
		else {
			Alphabet[S[i] - 'A']++;
		}
	}

	int cnt1 = 0;
	int index1 = 0;
	int cnt2 = 0;
	int index2 = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt1 < Alphabet[i]) {
			cnt2 = cnt1;
			index2 = index1;
			cnt1 = Alphabet[i];
			index1 = i;
		}
		else if (cnt2 < Alphabet[i]) {
			cnt2 = Alphabet[i];
			index2 = i;
		}
	}
	if (cnt1 == cnt2)
		cout << '?';
	else {
		char c = 'A' + index1;
		cout << c;
	}


	return 0;
}