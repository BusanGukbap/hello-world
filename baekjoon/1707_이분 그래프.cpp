#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int K, V, E;

const int MAX = 20000 + 1;

vector<int> vertex[MAX];
int color[MAX];
bool bin_graph;

void dfs(int index, int cur_color) {
	color[index] = cur_color;
	
	for (int i = 0; i < vertex[index].size(); i++) {
		int next = vertex[index][i];
		if (color[next] == 0)
			dfs(next, 3 - cur_color);
		else if (color[next] == cur_color)
			bin_graph = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> K;

	for (int test_case = 0; test_case < K; test_case++) {
		memset(color, 0, sizeof(color));
		for (int i = 0; i < MAX; i++) vertex[i].clear();
		cin >> V >> E;
		bin_graph = true;

		for (int i = 0; i < E; i++) {
			cin >> a >> b;

			vertex[a].push_back(b);
			vertex[b].push_back(a);
		}
		for (int i = 1; i <= V; i++)
			if (color[i] == 0)
				dfs(i, 1);

		if (bin_graph)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}