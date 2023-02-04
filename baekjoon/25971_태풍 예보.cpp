#include <bits/stdc++.h>

using namespace std;

long long int N, K, R, Q;

pair<pair<long long int, long long int>, int> typhoon[200010];
// ¹æÇâ
// (1, 0) = 1, (0, 1) = 2, (-1, 0) = 3, (0, -1) = 4

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K >> R >> Q;
	
	long long int before;
	for (long long int i = 0; i < K; i++) {
		long long int day, x, y;
		cin >> day >> x >> y;
		typhoon[day].first.first = x;
		typhoon[day].first.second = y;

		if (i == 0)
			before = day;
		else {
			long long int a = day - before;
			long long int b = ((typhoon[day].first.first - typhoon[before].first.first) / a);
			long long int c = ((typhoon[day].first.second - typhoon[before].first.second) / a);
			int dir = 1;
			if (b == 1 && c == 0)
				dir = 1;
			else if (b == 0 && c == 1)
				dir = 2;
			else if (b == -1 && c == 0)
				dir = 3;
			else if (b == 0 && c == -1)
				dir = 4;

			for (long long int j = before; j < day; j++) {
				typhoon[j].first.first = typhoon[before].first.first + b * (j - before);
				typhoon[j].first.second = typhoon[before].first.second + c * (j - before);
				typhoon[j].second = dir;
			}

			before = day;
		}
	}

	typhoon[N].second = typhoon[N - 1].second;

	while (Q--) {
		long long int day, x, y;
		cin >> day >> x >> y;

		long long int r2 = R * R;
		long long int distance = (typhoon[day].first.first - x) * (typhoon[day].first.first - x) + (typhoon[day].first.second - y) * (typhoon[day].first.second - y);

		if (distance > r2) {
			cout << "gori\n";
		}
		else {
			switch (typhoon[day].second) {
			case 1:
				if (y == typhoon[day].first.second)
					cout << "gori\n";
				else if (y > typhoon[day].first.second)
					cout << "safe\n";
				else if (y < typhoon[day].first.second)
					cout << "unsafe\n";
				break;
			case 2:
				if (x == typhoon[day].first.first)
					cout << "gori\n";
				else if (x < typhoon[day].first.first)
					cout << "safe\n";
				else if (x > typhoon[day].first.first)
					cout << "unsafe\n";
				break;
			case 3:
				if (y == typhoon[day].first.second)
					cout << "gori\n";
				else if (y > typhoon[day].first.second)
					cout << "unsafe\n";
				else if (y < typhoon[day].first.second)
					cout << "safe\n";
				break;
			case 4:
				if (x == typhoon[day].first.first)
					cout << "gori\n";
				else if (x < typhoon[day].first.first)
					cout << "unsafe\n";
				else if (x > typhoon[day].first.first)
					cout << "safe\n";
				break;
			}
		}

	}

	return 0;
}