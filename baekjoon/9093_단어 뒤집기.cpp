#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string input;
		getline(cin, input);
		input += ' ';
		stack<char> st;

		for (int j = 0; j < input.size(); j++) {
			if (input[j] == ' ') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ' ';
			}
			else
				st.push(input[j]);
		}

		cout << '\n';
	}

	return 0;
}