#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
bool visit[9];
int save[9];

void func(int index) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << save[i] << " ";
		}
		cout << '\n';
		return;
	}


	int before = 0;
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0 && (before != arr[i])) {
			before = save[index] = arr[i];
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
		cin >> arr[i];
	}

	sort(arr, arr + N);

	func(0);

	return 0;
}