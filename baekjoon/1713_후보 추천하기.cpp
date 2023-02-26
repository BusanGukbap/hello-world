#include <bits/stdc++.h>

using namespace std;

// N : 사진틀의 개수, M : 추천횟수
// 빈 사진틀이 있을 경우 추천학생 사진틀에 올림, 빈칸 없을경우 추천수 가장 낮으면서 오래된거 삭제 후 새로운거 개시
// 이미 사진틀에 있을경우 추천수만 증가, 삭제된 사진의 추천수는 0으로 초기화
int N, M;
int idx = 0, cnt = 0;
bool student[101];
vector<pair<int, pair<int, int>>> v; // {추천수, {등록일자, id} }

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	// 추천수 큰걸 앞으로
	if (a.first != b.first)
		return a.first > b.first;
	else
		return a.second.first > b.second.first;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int t = 1; t <= M; t++) {
		int temp; cin >> temp;
		// 이미 사진틀에 잇을 경우
		if (student[temp] == true) {
			for (int i = 0; i < v.size(); i++) {
				if (v[i].second.second == temp) {
					v[i].first++;
				}
			}
		}
		// 사진틀에 없는 경우
		else if (student[temp] == false) {
			// 사진틀에 자리가 다 찬 경우
			if (v.size() == N) {
				sort(v.begin(), v.end(), compare);
				pair<int, pair<int, int>> a = v[v.size() - 1];
				v.pop_back();
				student[a.second.second] = false;

				student[temp] = true;
				v.push_back({ 1, {t, temp} });

			}
			// 사진틀에 자리가 남은 경우
			else {
				student[temp] = true;
				v.push_back({ 1, {t, temp} });
			}
		}

	}

	for (int i = 1; i <= 100; i++) {
		if (student[i] == true)
			cout << i << ' ';
	}

	return 0;
}