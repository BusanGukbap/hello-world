#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

void solution() {
	double tall, weight;
	cin >> tall >> weight;

	if (tall >= 204 || (146 <= tall && tall < 159))
		cout << "4\n";
	else if (140.1 <= tall && tall < 146)
		cout << "5\n";
	else if (tall < 140.1)
		cout << "6\n";
	else if (tall < 161 && tall >= 159) {
		double temp = tall / 100;
		temp *= temp;
		temp = weight / temp;

		if (temp < 35 && temp >= 16)
			cout << "3\n";
		else
			cout << "4\n";
	}
	else {
		double temp = tall / 100;
		temp *= temp;
		temp = weight / temp;

		if (20 <= temp && temp < 25)
			cout << "1\n";
		else if ((18.5 <= temp && temp < 20) || (25 <= temp && temp < 30))
			cout << "2\n";
		else if ((16 <= temp && temp < 18.5) || (30 <= temp && temp < 35))
			cout << "3\n";
		else
			cout << "4\n";
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solution();
	}

	return 0;
}