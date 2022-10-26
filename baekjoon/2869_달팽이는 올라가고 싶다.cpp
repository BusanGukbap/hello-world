#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int A, B, V;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> V;	
	V -= A;
	if (V % (A - B) == 0) {
		cout << V / (A - B) + 1;
	}
	else
		cout << V / (A - B) + 2;



	return 0;
}