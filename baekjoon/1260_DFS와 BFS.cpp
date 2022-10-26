#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int N, M, V;
int board[MAX][MAX];
bool visited[MAX];
queue<int> q;

void clear() {
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}

void DFS(int index) {
	cout << index << " ";
	visited[index] = true;

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && board[index][i]) {
			DFS(i);
		}
	}
}

void BFS(int index) {
	q.push(index);
	visited[index] = true;
	cout << index << " ";

	while (!q.empty()) {
		index = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && board[index][i]) {
				visited[i] = true;
				q.push(i);
				cout << i << " ";
			}
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> V;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = 1;
	}

	clear();
	DFS(V);
	cout << '\n';
	clear();
	BFS(V);

	return 0;
}