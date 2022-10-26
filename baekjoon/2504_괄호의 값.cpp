#include <bits/stdc++.h>

using namespace std;

string str;
stack<char> S;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	bool can = true;
	int result = 0; int temp = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			S.push(str[i]);
			temp *= 2;
		}
		else if (str[i] == '[') {
			S.push(str[i]);
			temp *= 3;
		}
		else if (str[i] == ']') {
			if (S.empty() || S.top() != '[') {
				can = false;
				break;
			}
			
			if (str[i-1] == '[')
				result += temp;

			S.pop();
			temp /= 3;
		}
		else if (str[i] == ')') {
			if (S.empty() || S.top() != '(') {
				can = false;
				break;
			}

			if (str[i-1] == '(')
				result += temp;

			S.pop();
			temp /= 2;
		}
	}
	if (!can || !S.empty())
		cout << 0;
	else
		cout << result;
	
	return 0;
}