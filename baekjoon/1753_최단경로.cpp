#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define MAX 20001
#define INF 987654321

vector<pair<int, int>> Vertex[MAX];
int Dist[MAX];
int V, E, start_V;

void Dijkstra() {
	// 가중치, vertex -> 가중치가 낮은순으로 탐색해야 하므로 가중치를 first에 적음
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, start_V));
	Dist[start_V] = 0;

	while (!q.empty()) {
		int cur = q.top().second;
		int weight = -q.top().first;
		q.pop();

		for (int i = 0; i < Vertex[cur].size(); i++) {
			int next_vertex = Vertex[cur][i].first;
			int next_weight = Vertex[cur][i].second;

			if (Dist[next_vertex] > weight + next_weight) {
				Dist[next_vertex] = weight + next_weight;
				q.push(make_pair(-Dist[next_vertex], next_vertex));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (Dist[i] == INF)
			cout << "INF\n";
		else
			cout << Dist[i] << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int u, v, w;

	cin >> V >> E >> start_V;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		Vertex[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= V; i++)
		Dist[i] = INF;

	Dijkstra();

	return 0;
}