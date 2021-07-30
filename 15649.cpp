#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, M;
int arr[10]; // ������ �����ϴ� ��
bool visit[10]; // visit[i] = 0�϶� arr�� i�� ����, visit[i] = 1�϶� arr�� i�� ����

// index = arr�� ����ִ� ���� ����
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