#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int input[9];
int save[9];
bool visit[9];

void func(int index) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << save[i] << " ";
		}
		cout << '\n';
		return;
	}

	int before = -1;
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0 && before != input[i] && (index == 0 || save[index-1] <= input[i])) {
			before = input[i];
			save[index] = input[i];
			visit[i] = 1;
			func(index + 1);
			visit[i] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input, input + N);

	func(0);

	return 0;
}