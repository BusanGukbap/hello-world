#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> sosu;
bool arr[5000001];

void make_sosu() {
	for (int i = 2; i <= 5000000; i++) {
		if (arr[i] == true)
			continue;
		sosu.push_back(i);
		for (int j = i * 2; j <= 5000000; j += i) {
			arr[j] = true;
		}
	}
}

void func(int data) {
	int idx = 0;
	while (data > 1) {
		if (arr[data] == false) {
			cout << data << " ";
			break;
		}
		else if (data % sosu[idx] == 0) {
			cout << sosu[idx] << " ";
			data /= sosu[idx];
		}
		else
			idx++;
	}
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	int temp;
	cin >> N;
	make_sosu();
	for (int i = 0; i < N; i++) {
		cin >> temp;
		func(temp);
	}

	return 0;
}