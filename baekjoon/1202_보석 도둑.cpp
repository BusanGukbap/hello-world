#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long ans = 0;
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> gem(N);
	vector<int> bag(K);
	priority_queue<int> pq;

	for (int i = 0; i < N; i++)
		cin >> gem[i].first >> gem[i].second;
	for (int i = 0; i < K; i++)
		cin >> bag[i];
	sort(gem.begin(), gem.end());
	sort(bag.begin(), bag.end());

	int index = 0;
	for (int i = 0; i < K; i++) {
		while (index < N && gem[index].first <= bag[i]) {
			pq.push(gem[index++].second);
		}
		if (!pq.empty()) {
			ans += (long long)pq.top();
			pq.pop();
		}
	}

	cout << ans << '\n';

	return 0;
}