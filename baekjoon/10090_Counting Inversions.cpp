#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int N;
vector<int> arr, tempArr;
ll InversionCnt;

void InversionCounting(int start, int end) {
	if (start == end)
		return;

	int mid = (start + end) / 2;

	InversionCounting(start, mid);
	InversionCounting(mid + 1, end);

	int i = start;
	int j = mid + 1;
	long long tempInv = 0;
	int index = 0;

	while (i <= mid && j <= end) {
		if (arr[i] < arr[j])
			tempArr[index++] = arr[i++];
		else {
			InversionCnt += (mid - i + 1);
			tempArr[index++] = arr[j++];
		}
	}
	while (i <= mid) {
		tempArr[index++] = arr[i++];
	}
	while (j <= end) {
		tempArr[index++] = arr[j++];
	}

	for (int k = start; k <= end; k++) {
		arr[k] = tempArr[k - start];
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	InversionCnt = 0;
	cin >> N;
	arr.resize(N + 1);
	tempArr.resize(N + 1);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	InversionCounting(0, N - 1);

	cout << InversionCnt << '\n';


	return 0;
}