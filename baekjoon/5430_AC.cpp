#include <bits/stdc++.h>

using namespace std;
	
string p;
int N;
deque<int> dq;

void insert_dq(string temp) {
	int num = 0;
	for (int i = 0; i < temp.length(); i++) {
		if (temp[i] == '[')
			continue;
		if (temp[i] == ',' || temp[i] == ']') {
			if (num == 0)
				continue;
			dq.push_back(num);
			num = 0;
		}
		else {
			num *= 10;
			num += temp[i] - '0';
		}
	}
}

void solution() {
	bool PF = true;			// true => pop_front, false => pop_back
	bool ERROR = false;

	for (int i = 0; i < p.length(); i++) {
		if (p[i] == 'R') {
			if (PF)
				PF = false;
			else
				PF = true;
			continue;
		}
		
		
		// D인데 비었을때
		if (dq.empty()) {
			ERROR = true;
			break;
		}
		if (PF) {
			dq.pop_front();
		}
		else
			dq.pop_back();
	}

	if (ERROR)
		cout << "error\n";
	else {
		cout << "[";
		if (PF) {
			while (!dq.empty()) {
				cout << dq.front();
				dq.pop_front();
				if (dq.size() > 0)
					cout << ',';
			}
		}
		else {
			while (!dq.empty()) {
				cout << dq.back();
				dq.pop_back();
				if (dq.size() > 0)
					cout << ',';
			}
		}
		cout << "]\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int TC;
	string temp;
	cin >> TC;
	while (TC--) {
		cin >> p;
		cin >> N;
		dq.clear();
		cin >> temp;

		insert_dq(temp);
		solution();
	}


	return 0;
}