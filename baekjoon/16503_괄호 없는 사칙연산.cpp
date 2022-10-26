#include<bits/stdc++.h>

using namespace std;

int a, b, c;
char o1, o2;

int cal(int number1, int number2, char o) {
	if (o == '+')
		return number1 + number2;
	else if (o == '*')
		return number1 * number2;
	else if (o == '/')
		return number1 / number2;
	else {
		return number1 - number2;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> a >> o1 >> b >> o2 >> c;
	int ans1, ans2;

	int temp = cal(a, b, o1);
	ans1 = cal(temp, c, o2);
	temp = cal(b, c, o2);
	ans2 = cal(a, temp, o1);
	if (ans1 < ans2)
		cout << ans1 << '\n' << ans2;
	else
		cout << ans2 << '\n' << ans1;

	return 0;
}