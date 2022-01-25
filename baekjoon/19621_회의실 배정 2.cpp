#include <bits/stdc++.h>

using namespace std;

int N;

typedef struct node {
	int start;
	int finish;
	int people;
} node;

node meeting[25];
int the_most;

void dynamic(int idx, int total) {
	if (idx >= N) {
		if (total > the_most)
			the_most = total;
		return;
	}

	dynamic(idx + 2, total + meeting[idx].people);
	dynamic(idx + 1, total);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> meeting[i].start >> meeting[i].finish >> meeting[i].people;
	}

	dynamic(0, 0);
	cout << the_most;

	return 0;
}