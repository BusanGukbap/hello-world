#include <bits/stdc++.h>

using namespace std;

int N;
vector <string> ans;
bool check[10];

bool cmp(string A, string B) {
	if (A.length() == B.length()) {
		for (int i = 0; i < A.length(); i++) {
			if (A[i] == B[i])
				continue;
			return A[i] < B[i];
		}
	}
	else {
		return (A.length() < B.length());
	}
}

void backtracking(int index) {
	string temp = "";
	for (int i = 9; i >= 0; i--) {
		if (check[i] == true)
			temp.push_back(i + '0');
	}
	ans.push_back(temp);

	for (int i = index; i < 10; i++) {
		if (check[i] == false) {
			check[i] = true;
			backtracking(i + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	if (N >= 1023)
		cout << -1;
	else {
		backtracking(0);
		sort(ans.begin(), ans.end(), cmp);
		cout << ans[N+1];
	}

	return 0;
}