#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long int A[4001], B[4001], C[4001], D[4001];
vector<int> x;
long long int cnt;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
}

void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			x.push_back(C[i] + D[j]);
		}
	}

	sort(x.begin(), x.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// A와B의 합의 반대값 구하기
			auto d = equal_range(x.begin(), x.end(), -(A[i] + B[j]));
			cnt += d.second - d.first;
		//	cnt += distance(d.first, d.second);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	solution();

	cout << cnt << '\n';

	return 0;
}