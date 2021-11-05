#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;
#define MAX 500001

int N;
int total;
bool Visit[MAX];
vector<int> Tree[MAX];

//    root까지 거리   현재 노드 번호
void dfs(long long index, int node_number) {
	// leaf일때
	if (node_number != 1 && Tree[node_number].size() == 1) {
		total += index;
		return;
	}

	// leaf가 아닐때
	Visit[node_number] = true;
	for (int p : Tree[node_number]) {
		if (!Visit[p])
			dfs(index + 1, p);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	dfs(0, 1);

	if (total % 2 == 0)
		cout << "No\n";
	else
		cout << "Yes\n";

	return 0;
}