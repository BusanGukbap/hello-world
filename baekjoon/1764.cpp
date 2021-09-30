#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M;

vector <string> no_listen;
vector <string> result;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		no_listen.push_back(str);
	}

	sort(no_listen.begin(), no_listen.end());

	for (int i = 0; i < M; i++) {
		cin >> str;

		if (binary_search(no_listen.begin(), no_listen.end(), str))
			result.push_back(str);
	}

	sort(result.begin(), result.end());

	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}


	return 0;
}