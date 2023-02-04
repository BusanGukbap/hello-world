#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> domino[500000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> domino[i].first >> domino[i].second;
	}
	sort(domino, domino + N);
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (domino[i].second == 0)
			continue;

		ans++;
		int index = i;
		while (1) {
			int len = domino[index].first + domino[index].second;
			
			if (len < domino[index + 1].first)
				break;
			else {
				domino[index].second = 0;
				index++;
			}
		}
		i = index;
	}

	cout << ans << '\n';

	return 0;
}