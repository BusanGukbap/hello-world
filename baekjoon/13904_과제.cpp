#include <bits/stdc++.h>

using namespace std;

int N;
vector <pair<int, int>> homework;
int score;
int result = 0;
bool day[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int deadline, score;
		cin >> deadline >> score;
		homework.push_back({ score, deadline });
	}
	sort(homework.begin(), homework.end(), greater<pair<int, int>>());

	for (int i = 0; i < N; i++) {
		int index = homework[i].second;
		while (index >= 1) {
			if (day[index] == false) {
				day[index] = true;
				result += homework[i].first;
				break;
			}
			
			index--;
		}
	}

	cout << result << '\n';

	return 0;
}