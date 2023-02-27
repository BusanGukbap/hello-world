#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int age, weight;
	string name;
	cin >> name >> age >> weight;

	while (name != "#") {
		if (age > 17 || weight >= 80) {
			cout << name << ' ' << "Senior\n";
		}
		else
			cout << name << ' ' << "Junior\n";

		cin >> name >> age >> weight;
	}
	
	return 0;
}