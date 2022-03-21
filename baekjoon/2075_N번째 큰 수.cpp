#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue <int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			pq.push(temp);
			if (pq.size() > N)
				pq.pop();
		}
	}

	cout << pq.top();

	return 0;
}