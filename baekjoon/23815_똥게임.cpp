#include <bits/stdc++.h>

using namespace std;

int N, maxx;
int x[100001][2];
char c[100001][2];
int dp[100001][2]; // [i�� �������� ��][skipp ����]

int cal(int index, int people, int choice) {
	char symbol = c[index][choice];
	int temp = x[index][choice];

	// 1. ���ϱ�
	if (symbol == '+')
		return people + temp;
	// 2. ����
	else if (symbol == '-')
		return people - temp;
	// 3. ���ϱ�
	else if (symbol == '*')
		return people * temp;
	// 4. ������
	else if (symbol == '/')
		return people / temp;
}

// 
void func(int skipp, int index, int people) {
	if (index == N) {
		if (dp[N][skipp] > maxx)
			maxx = dp[N][skipp];
		return;
	}

	// skip�� ����ϴ� ���
	if (skipp == 0) {
		if (dp[index + 1][1] < people) {
			dp[index + 1][1] = people;
			func(1, index + 1, people);
		}
	}

	// ù��° ����, �ι�° ����
	int first_choice, second_choice;
	first_choice = cal(index, people, 0);
	second_choice = cal(index, people, 1);

	// �Ѵ� 0�̸� Ž������
	if (first_choice <= 0 && second_choice <= 0)
		return;
	else {
		people = first_choice > second_choice ? first_choice : second_choice;
		if (people > dp[index + 1][skipp]) {
			dp[index + 1][skipp] = people;
			func(skipp, index + 1, people);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c[i][0] >> x[i][0];
		cin >> c[i][1] >> x[i][1];
	}

	func(0, 0, 1);

	if (maxx == 0)
		cout << "ddong game";
	else
		cout << maxx;

	return 0;
}