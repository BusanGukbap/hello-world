#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll arr[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		ll temp; cin >> temp;
		int start = 0, end = N-1;

		while (start <= end) {
			int mid = (start + end) / 2;
			if (arr[mid] == temp) {
				cout << "1\n";
				break;	
			}
			else if (arr[mid] > temp)
				end = mid - 1;
			else if (arr[mid] < temp)
				start = mid + 1;
		}
		if (start > end)
			cout << "0\n";

	}


	return 0;
}