#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M;

vector <string> pokemon;
map<string, int> pokemon2;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	string temp;
	int a;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		pokemon.push_back(temp);
		pokemon2.insert({ temp, i + 1 });
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (temp[0] <= '9' && temp[0] >= '0') {
			a = 0;
			for (int j = 0; j < temp.length(); j++) {
				a *= 10;
				a += temp[j] - '0';
			}

			cout << pokemon[a - 1] << '\n';
		}

		else {
			cout << pokemon2[temp] << '\n';
		}
	}

	return 0;
}