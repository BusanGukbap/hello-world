#include <bits/stdc++.h>

using namespace std;

bool arr[10010];
vector <int> prime;

void sosu() {
	for (int i = 2; i <= 10000; i++) {
		if (arr[i] == false) {
			prime.push_back(i);
			for (int j = i * 2; j <= 10000; j += i)
				arr[j] = true;
		}
	}
}

bool Is_Prime(int num) {
	if (num == 1)
		return false;
	else if (num % 2 == 0)
		return false;
	
	for (int index = 0; prime[index] <= sqrt(num); index++) {
		if (num % prime[index] == 0)
			return false;
	}

	return true;
}

void Palindrome_Sosu(int first, int last) {
	for (int num = first; num <= last; num++) {
		if (num % 2 == 0)
			continue;

		int temp = 0;
		int data = num;

		while (data) {
			temp *= 10;
			temp += data % 10;
			data /= 10;
		}

		if (num - temp == 0 && Is_Prime(num)) {
			cout << num << '\n';
		}
	}

	cout << -1 << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int first, last;
	cin >> first >> last;

	sosu();

	Palindrome_Sosu(first, last);

	return 0;
}