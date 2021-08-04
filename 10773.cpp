#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>

using namespace std;
int K;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack <int> S;
	
	cin >> K;
	int temp;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		if (temp == 0) {
			S.pop();
		}
		else {
			S.push(temp);
		}
	}

	int total = 0;
	while (!S.empty()) {
		total += S.top();
		S.pop();
	}

	cout << total;

	return 0;
}