#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int B, C;
	cin >> B >> C;

	long long int total = N;
	int student;
	for (int i = 0; i < N; i++) {
		student = arr[i] - B;
		if (student > 0) {
			total += student / C;
			if (student % C != 0)
				total += 1;
		}
	}
	
	cout << total;

	return 0;
}