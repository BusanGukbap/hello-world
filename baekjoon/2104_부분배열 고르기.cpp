#include <iostream>

using namespace std;

int N;
long long arr[100010];

long long func(int start, int end) {
	if (start == end)
		return arr[start] * arr[end];

	// 최대값이 나오는 경우의 수  1.왼쪽에 모여있을때, 2. 오른쪽에 모여있을때, 3. 중앙에 모여있을 때
	// 왼쪽, 오른쪽 중에서 큰값 고르기
	int mid = (start + end) / 2;
	long long result = max(func(start, mid), func(mid + 1, end));

	// 중간값을 포함하는 경우
	int left = mid;
	int right = mid + 1;

	long long sum = arr[left] + arr[right];
	long long minVal = min(arr[left], arr[right]);

	result = max(result, sum * minVal);

	while (left > start || right < end) {
		// 중앙에서 오른쪽거 추가하기
		if (right < end && (left == start || arr[left - 1] < arr[right + 1])) {
			sum += arr[++right];
			minVal = min(minVal, (long long)arr[right]);
		}
		// 중앙에서 왼쪽거 추가하기
		else {
			sum += arr[--left];
			minVal = min(minVal, (long long)arr[left]);
		}
		
		long long temp = sum * minVal;
		result = max(temp, result);
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	cout << func(1, N) << '\n';

	return 0;
}