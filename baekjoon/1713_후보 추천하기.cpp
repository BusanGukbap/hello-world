#include <bits/stdc++.h>

using namespace std;

// N : ����Ʋ�� ����, M : ��õȽ��
// �� ����Ʋ�� ���� ��� ��õ�л� ����Ʋ�� �ø�, ��ĭ ������� ��õ�� ���� �����鼭 �����Ȱ� ���� �� ���ο�� ����
// �̹� ����Ʋ�� ������� ��õ���� ����, ������ ������ ��õ���� 0���� �ʱ�ȭ
int N, M;
int idx = 0, cnt = 0;
bool student[101];
vector<pair<int, pair<int, int>>> v; // {��õ��, {�������, id} }

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	// ��õ�� ū�� ������
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
		// �̹� ����Ʋ�� ���� ���
		if (student[temp] == true) {
			for (int i = 0; i < v.size(); i++) {
				if (v[i].second.second == temp) {
					v[i].first++;
				}
			}
		}
		// ����Ʋ�� ���� ���
		else if (student[temp] == false) {
			// ����Ʋ�� �ڸ��� �� �� ���
			if (v.size() == N) {
				sort(v.begin(), v.end(), compare);
				pair<int, pair<int, int>> a = v[v.size() - 1];
				v.pop_back();
				student[a.second.second] = false;

				student[temp] = true;
				v.push_back({ 1, {t, temp} });

			}
			// ����Ʋ�� �ڸ��� ���� ���
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