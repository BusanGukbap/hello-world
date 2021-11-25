#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M;

vector <int> city;

void make_set() {
	for (int i = 0; i <= N; i++)
		city.push_back(i);
}

int find(int x) {
	if (city[x] == x)
		return x;
	else
		return find(city[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	city[y] = x;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a;

	cin >> N >> M;
	make_set();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a;
			if (i == j)
				continue;
			if (a == 1) {
				Union(i, j);
			}
		}
	}

	int before, i;
	bool flag = true;
	cin >> a;
	before = find(a);
	for (i = 2; i <= M; i++) {
		cin >> a;
		int temp = find(a);
		if (temp != before) {
			flag = false;
			break;
		}
	}

	if (flag == false)
		cout << "NO";
	else
		cout << "YES";
	
	return 0;
}