#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pair<int, int>> input(N);
		
		int temp;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			input[i].first = temp;
			input[i].second = i + 1;
		}

		sort(input.begin(), input.end());

		cout << input[0].second << " " << input[N - 1].second << '\n';
	}




	return 0;
}