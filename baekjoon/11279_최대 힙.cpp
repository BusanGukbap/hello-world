#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int> max_heap;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int temp;
	while (N--) {
		cin >> temp;
		if (temp == 0) {
			if (max_heap.empty())
				cout << "0\n";
			else {
				cout << max_heap.top() << '\n';
				max_heap.pop();
			}
		}

		else
			max_heap.push(temp);
	}

	return 0;
}