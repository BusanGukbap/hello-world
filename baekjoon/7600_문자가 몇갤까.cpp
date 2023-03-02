#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	bool alphabet[26];
	while (1) {
		getline(cin, s);
		if (s == "#")
			break;
		for (int i = 0; i < 26; i++)
			alphabet[i] = false;

		for (int i = 0; i < s.length(); i++) {
			if ('a' <= s[i] && s[i] <= 'z')
				alphabet[s[i] - 'a'] = true;
			if ('A' <= s[i] && s[i] <= 'Z')
				alphabet[s[i] - 'A'] = true;
		}

		int cnt = 0;
		for (int i = 0; i < 26; i++)
			if (alphabet[i])
				cnt++;

		cout << cnt << '\n';
	}

	return 0;
}