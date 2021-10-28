#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int T, K;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	char c;
	int index;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> K;
		multiset<int> Q;
		for (int i = 0; i < K; i++) {
			cin >> c >> index;
			if (c == 'I')
				Q.insert(index);

			else {
				if (Q.empty())
					continue;

				// 최소값 삭제
				if (index == -1)
					Q.erase(Q.begin());
				
				// 최대값 삭제
				else if (index == 1) {
					auto iter = Q.end();
					iter--;
					Q.erase(iter);
				}
			}
		}
		if (Q.empty())
			cout << "EMPTY" << '\n';
		else {
			auto end_iter = Q.end();
			end_iter--;
			cout << *end_iter << ' ' << *Q.begin() << '\n';
		}
	}

	return 0;
}