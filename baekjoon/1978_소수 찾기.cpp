#include <iostream>

using namespace std;

bool num[1001];

void sosu() {
	num[1] = false;
	for (int i = 2; i <= 1000; i++) {
		if (num[i] == true) {
			int cnt = 2;
			while (cnt * i <= 1000) {
				num[cnt * i] = false;
				cnt++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= 1000; i++)
		num[i] = true;
	sosu();

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		if (num[temp])
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}