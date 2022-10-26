#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
string input_data;
vector <char> alphabet;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> input_data;
	for (int i = 0; i < input_data.length(); i++) {
		alphabet.push_back(input_data[i]);
	}
	sort(alphabet.begin(), alphabet.end());

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0)
			for (int j = 0; j < input_data.length(); j++)
				cout << alphabet[j];
		else
			for (int j = input_data.length()-1; j >= 0; j--)
				cout << alphabet[j];
	}


	return 0;
}