#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

long long int res;
bool cant_cal = false;
string input;

long long int cal(long long int a, long long int b, char data) {
	if (data == '+') {
		return (a + b);
	}
	else if (data == 'x') {
		return (a * b);
	}
	else if (data == '-') {
		return (a - b);
	}
	else if (data == '/') {
		if (b == 0) {
			cant_cal = true;
			return 1;
		}
		return (a / b);
	}
}

void change_number() {
	bool first = true;
	int idx = 0;
	long long int temp = 0;
	char data;
	int last = input.length() - 1;
	queue<char> Q;

	while (1) {
		if (input[idx] == '=') {
			Q.push('=');
			if (first) {
				res = temp;
				break;
			}
			if (idx != last) {
				cant_cal = true;
				idx++;
				break;
			}
			res = cal(res, temp, data);
			break;
		}
		// 0
		else if (input[idx] == 'Z') {
			Q.push('0');
			temp *= 10;
			temp += 0;
			idx += 4;
		}
		// 1
		else if (input[idx] == 'O') {
			Q.push('1');
			temp *= 10;
			temp += 1;
			idx += 3;
		}
		// 2
		else if (input[idx] == 'T' && input[idx + 1] == 'W') {
			Q.push('2');
			temp *= 10;
			temp += 2;
			idx += 3;
		}
		// 3
		else if (input[idx] == 'T' && input[idx + 1] == 'H') {
			Q.push('3');
			temp *= 10;
			temp += 3;
			idx += 5;
		}
		// 4
		else if (input[idx] == 'F' && input[idx + 1] == 'O') {
			Q.push('4');
			temp *= 10;
			temp += 4;
			idx += 4;
		}
		// 5
		else if (input[idx] == 'F' && input[idx + 1] == 'I') {
			Q.push('5');
			temp *= 10;
			temp += 5;
			idx += 4;
		}
		// 6
		else if (input[idx] == 'S' && input[idx + 1] == 'I') {
			Q.push('6');
			temp *= 10;
			temp += 6;
			idx += 3;
		}
		// 7
		else if (input[idx] == 'S' && input[idx + 1] == 'E') {
			Q.push('7');
			temp *= 10;
			temp += 7;
			idx += 5;
		}
		// 8
		else if (input[idx] == 'E') {
			Q.push('8');
			temp *= 10;
			temp += 8;
			idx += 5;
		}
		// 9
		else if (input[idx] == 'N') {
			Q.push('9');
			temp *= 10;
			temp += 9;
			idx += 4;
		}
		else if (input[idx] == 'x' || input[idx] == '+' || 
				 input[idx] == '-' || input[idx] == '/') {
			Q.push(input[idx]);
			if (first) {
				first = false;
				res = temp;
				temp = 0;
				data = input[idx];
			}
			else {
				if (input[idx - 1] == 'x' || input[idx - 1] == '+' ||
					input[idx - 1] == '-' || input[idx - 1] == '/') {
					cant_cal = true;
					break;
				}
				res = cal(res, temp, data);
				data = input[idx];
				temp = 0;
			}
			idx++;
		}
		else {
			cant_cal = true;
			idx++;
		}
	}
	if (!cant_cal) {
		while (!Q.empty()) {
			cout << Q.front();
			Q.pop();
		}
		cout << '\n';
	}
	
}

void change_string() {
	if (cant_cal) {
		cout << "Madness!";
		return;
	}

	long long int temp = res;
	stack<string> S;
	if (temp < 0) {
		temp *= -1;
	}

	while (temp) {
		long long int a = temp % 10;
		if (a == 0)
			S.push("ZERO");
		else if (a == 1)
			S.push("ONE");
		else if (a == 2)
			S.push("TWO");
		else if (a == 3)
			S.push("THREE");
		else if (a == 4)
			S.push("FOUR");
		else if (a == 5)
			S.push("FIVE");
		else if (a == 6)
			S.push("SIX");
		else if (a == 7)
			S.push("SEVEN");
		else if (a == 8)
			S.push("EIGHT");
		else if (a == 9)
			S.push("NINE");
		temp /= 10;
	}

	if (res < 0)
		cout << "-";
	while (!S.empty()) {
		string a = S.top();
		cout << a;
		S.pop();
	}

	if (res == 0)
		cout << "ZERO";
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> input;
	change_number();
	change_string();

	return 0;
}