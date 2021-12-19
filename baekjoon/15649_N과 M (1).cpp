#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, M;
int arr[10]; // 수열을 저장하는 곳
bool visit[10]; // visit[i] = 0일땐 arr에 i가 없음, visit[i] = 1일땐 arr에 i가 있음

// index = arr에 담겨있는 수의 개수
void func(int index) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			arr[index] = i;
			visit[i] = 1;
			func(index+1);
			visit[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	func(0);

	return 0;
}