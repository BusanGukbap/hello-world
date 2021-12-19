#include <bits/stdc++.h>

using namespace std;

bool alphabet[26];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string S;
	int K;
	cin >> S >> K;

	string result = "";
	int cnt = 1;
	
	char a, b;
	for (int i = 1; i < S.length(); i++) {
		a = S[i - 1];
		b = S[i];
		
		if ('Z' < a) {
			a = a - 'a' + 'A';
		}
		if ('Z' < b) {
			b = b - 'a' + 'A';
		}
		if (a == b) {
			cnt++;
		}
		else {
			if (alphabet[a - 'A'] == true) {
				cnt = 1;
			} 
			else {
				if (cnt >= K) {
					result.push_back('1');
				}
				else {
					result.push_back('0');
				}
				cnt = 1;
				alphabet[a - 'A'] = true;
			}
		}
	}

	if (alphabet[b - 'A'] == true) {
		cnt = 1;
	}
	else {
		if (cnt >= K) {
			result.push_back('1');
		}
		else {
			result.push_back('0');
		}
		cnt = 1;
		alphabet[a - 'A'] = true;
	}


	cout << result;

	return 0;
}