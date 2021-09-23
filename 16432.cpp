#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
int a[1000][10];
bool visited[1000][10];
vector<int> ans;

void dfs(int day) {
	if (day == N) {
		return;
	}
	
	int cnt = 0;
	for (int i = 1; i <= a[day][0]; i++) {
		if (ans.size() == N)
			return;
		if ((day == 0 || ans.back() != a[day][i]) && (visited[day][i] == false)) {
			visited[day][i] = true;
			ans.push_back(a[day][i]);
			dfs(day + 1);
			if (ans.size() == N)
				return;
			ans.pop_back();
		}
	}

	return;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int m, last = -1;

	for (int i = 0; i < N; i++) {
		cin >> a[i][0];
		for (int j = 1; j <= a[i][0]; j++)
			cin >> a[i][j];
	}

	dfs(0);

	if (ans.size() != N)
		cout << -1;
	else {
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
	}

	return 0;
}