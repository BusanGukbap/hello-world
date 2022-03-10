#include <bits/stdc++.h>

using namespace std;

int N, K;
bool Visit[5001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	cout << '<';
	
	int cnt = 0, index = K;
	while (cnt < N) {
		cout << index;
		Visit[index] = true;
		cnt++;

		if (cnt == N) {
			cout << '>';
			continue;
		}
		
		cout << ", ";
		for (int i = 1; i <= K; i++) {
			index++;
			if (index > N)
				index = 1;
			if (Visit[index] == true)
				i--;
		}

	}


	return 0;
}