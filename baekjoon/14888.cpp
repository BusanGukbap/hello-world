#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int A[12];
int N;
//+, -, *, / °³¼ö
int Operator[4];
// 0->+, 1->-, 2->*, 3->/
vector<int> S;
int minn = 1000000000, maxx = -1000000000;

void cal() {
	int res = A[0];
	for (int i = 0; i < N-1; i++) {
		if (S[i] == 0) {
			res += A[i + 1];
		}
		else if (S[i] == 1) {
			res -= A[i + 1];
		}
		else if (S[i] == 2) {
			res *= A[i + 1];
		}
		else if (S[i] == 3) {
			res /= A[i + 1];
		}
	}
	if (res > maxx)
		maxx = res;
	if (res < minn)
		minn = res;
}

void func(int index) {
	if (index == N - 1) {
		cal();
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (Operator[i]) {
			S.push_back(i);
			Operator[i]--;
			func(index+1);
			Operator[i]++;
			S.pop_back();
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < 4; i++)
		cin >> Operator[i];

	func(0);

	cout << maxx << '\n' << minn << '\n';

	return 0;
}