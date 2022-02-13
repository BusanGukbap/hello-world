#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int test_case, pole_length, N;
vector<int> ant;

void shortest() {
	int ans = 0, temp;
	for (int i = 0; i < N; i++) {
		temp = (ant[i] < pole_length - ant[i]) ? ant[i] : (pole_length - ant[i]);
		if (ans < temp)
			ans = temp;
	}
	cout << ans << " ";
}

void longest() {
	int ans = 0, temp;
	for (int i = 0; i < N; i++) {
		temp = (ant[i] > pole_length - ant[i]) ? ant[i] : (pole_length - ant[i]);
		if (ans < temp)
			ans = temp;
	}
	cout << ans << "\n";
}

void solution() {
	shortest();
	longest();
}

void input() {
	cin >> test_case;
	
	for (int T = 0; T < test_case; T++) {
		cin >> pole_length >> N;
		ant.clear();
		
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			ant.push_back(temp);
		}

		solution();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}