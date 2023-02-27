#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	while (n--) {
		string str; cin >> str;
		int a = 0, b =0 ;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				b++;
			else a++;
		}
		if (a >= b)
			cout << str << '\n' << 0 << '\n';
		else
			cout << str << '\n' << 1 << '\n';
	}

	return 0;
}