#include <iostream>

using namespace std;

string A, B;
string a = ""; // A&B
string b = ""; // A|B
string c = ""; // A^B
string d = ""; // ~A
string e = ""; // ~B

void andFunc(int idx) {
	if (A[idx] == '1' && B[idx] == '1')
		a += '1';
	else
		a += '0';
}

void orFunc(int idx) {
	if (A[idx] == '1' || B[idx] == '1')
		b += '1';
	else
		b += '0';
}

void xorFunc(int idx) {
	if (A[idx] == B[idx])
		c += '0';
	else
		c += '1';
}

void notFunc(int idx) {
	if (A[idx] == '1')
		d += '0';
	else
		d += '1';
	if (B[idx] == '1')
		e += '0';
	else
		e += '1';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> A;
	cin >> B;


	for (int i = 0; i < A.length(); i++) {
		andFunc(i);
		orFunc(i);
		xorFunc(i);
		notFunc(i);
	}

	cout << a << '\n';
	cout << b << '\n';
	cout << c << '\n';
	cout << d << '\n';
	cout << e << '\n';

	return 0;
}