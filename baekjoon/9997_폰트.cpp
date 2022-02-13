#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int all_alphabet = (1 << 26) - 1;
int N;
vector<int> word;
int ans;

void func(int index, int data) {
	if (index == N) {
		data ^= all_alphabet;
		if (data == 0)
			ans++;
		return;
	}
	
	func(index + 1, data);
	func(index + 1, data | word[index]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		int temp = 0;
		for (int i = 0; i < input.length(); i++) {
			temp |= 1 << input[i] - 'a';
		}

		word.push_back(temp);
	}

	func(0, 0);
	cout << ans;

	return 0;
}