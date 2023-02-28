#include <iostream>
#include <deque>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

deque<ll> GoStack;
vector<string> program;
vector<ll> programNum;
bool quit = false;
int N;

void input() {
	string temp;

	// Program �Է�
	while (1) {
		cin >> temp;

		if (temp == "QUIT") {
			quit = true;
			return;
		}
		if (temp == "END")
			break;

		program.push_back(temp);
		if (temp == "NUM") {
			int a; cin >> a;
			programNum.push_back(a);
		}
	}
}

void func() {
	int numIdx = 0;

	for (int i = 0; i < program.size(); i++) {
		string a = program[i];
		
		if (a == "NUM") {
			GoStack.push_back(programNum[numIdx++]);
		}
		else if (a == "POP") {
			// ù��° ���ڰ� ������� ����ó��
			if (GoStack.empty()) {
				cout << "ERROR\n";
				return;
			}

			GoStack.pop_back();
		}
		else if (a == "INV") {
			// ù��° ���ڰ� ������� ����ó��
			if (GoStack.empty()) {
				cout << "ERROR\n";
				return;
			}

			ll temp = GoStack.back();
			GoStack.pop_back();
			temp *= (-1);
			GoStack.push_back(temp);
		}
		else if (a == "DUP") {
			// ù��° ���ڰ� ������� ����ó��
			if (GoStack.empty()) {
				cout << "ERROR\n";
				return;
			}

			ll temp = GoStack.back();
			GoStack.push_back(temp);
		}
		else if (a == "SWP") {
			// ������ ���� 2���� ���� ���
			if (GoStack.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			ll temp1 = GoStack.back();
			GoStack.pop_back();
			ll temp2 = GoStack.back();
			GoStack.pop_back();
			
			GoStack.push_back(temp1);
			GoStack.push_back(temp2);
		}
		else if (a == "ADD") {
			// ������ ���� 2���� ���� ���
			if (GoStack.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			ll temp1 = GoStack.back();
			GoStack.pop_back();
			ll temp2 = GoStack.back();
			GoStack.pop_back();

			ll temp3 = temp1 + temp2;
			if (temp3 > 1000000000 || temp3 < -1000000000) {
				cout << "ERROR\n";
				return;
			}
			GoStack.push_back(temp3);
		}
		else if (a == "SUB") {
			// ������ ���� 2���� ���� ���
			if (GoStack.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			ll temp1 = GoStack.back();
			GoStack.pop_back();
			ll temp2 = GoStack.back();
			GoStack.pop_back();

			ll temp3 = temp2 - temp1;
			if (temp3 > 1000000000 || temp3 < -1000000000) {
				cout << "ERROR\n";
				return;
			}

			GoStack.push_back(temp3);
		}
		else if (a == "MUL") {
			// ������ ���� 2���� ���� ���
			if (GoStack.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			ll temp1 = GoStack.back();
			GoStack.pop_back();
			ll temp2 = GoStack.back();
			GoStack.pop_back();

			ll temp3 = temp1 * temp2;
			if (temp3 > 1000000000 || temp3 < -1000000000) {
				cout << "ERROR\n";
				return;
			}

			GoStack.push_back(temp3);
		}
		else if (a == "DIV") {
			// ������ ���� 2���� ���� ���
			if (GoStack.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			ll temp1 = GoStack.back();
			GoStack.pop_back();
			ll temp2 = GoStack.back();
			GoStack.pop_back();

			if (temp1 == 0) {
				cout << "ERROR\n";
				return;
			}
			
			ll temp3 = temp2 / temp1;
			if ((temp1 < 0 && temp2 < 0) || (temp1 > 0 && temp2 > 0))
				temp3 = abs(temp3);
			else
				temp3 = -abs(temp3);

			GoStack.push_back(temp3);
		}
		else if (a == "MOD") {
			// ������ ���� 2���� ���� ���
			if (GoStack.size() < 2) {
				cout << "ERROR\n";
				return;
			}

			ll temp1 = GoStack.back();
			GoStack.pop_back();
			ll temp2 = GoStack.back();
			GoStack.pop_back();

			if (temp1 == 0) {
				cout << "ERROR\n";
				return;
			}

			ll temp3 = temp2 % temp1;
			if (temp2 < 0)
				temp3 = -abs(temp3);
			else
				temp3 = abs(temp3);

			GoStack.push_back(temp3);
		}
	}

	if (GoStack.size() != 1) {
		cout << "ERROR\n";
	}
	else {
		cout << GoStack.front() << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		program.clear();
		programNum.clear();

		input();
		
		if (quit) {
			break;
		}

		cin >> N;
		for (int i = 1; i <= N; i++) {
			GoStack.clear();
			int temp; cin >> temp;
			GoStack.push_back(temp);
			func();
		}

		cout << '\n';
	}


	return 0;
}