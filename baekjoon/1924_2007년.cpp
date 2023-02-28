#include <iostream>

using namespace std;

string yoil[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int a, b;
	cin >> a >> b;

	int total = 0;
	for (int i = 1; i < a; i++) {
		total += month[i];
	}
	total += b;	
	total %= 7;
	cout << yoil[total] << '\n';

	return 0;
}