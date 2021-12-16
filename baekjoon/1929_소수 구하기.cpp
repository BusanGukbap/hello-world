#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;
int M, N;

bool arr[1000001];
queue <int> v;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;

	arr[1] = true;
	for (int i = 2; i <= N; i++) {
		if (arr[i] == true)
			continue;
		arr[i] = true;
		if (i >= M)
			v.push(i);
		for (int j = 2; j * i <= N; j++)
			arr[i * j] = true;
	}

	while(!v.empty()) {
		cout << v.front() << '\n';
		v.pop();
	}

	return 0;
}