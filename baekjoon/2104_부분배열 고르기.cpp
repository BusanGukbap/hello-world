#include <iostream>

using namespace std;

int N;
long long arr[100010];

long long func(int start, int end) {
	if (start == end)
		return arr[start] * arr[end];

	// �ִ밪�� ������ ����� ��  1.���ʿ� ��������, 2. �����ʿ� ��������, 3. �߾ӿ� ������ ��
	// ����, ������ �߿��� ū�� ����
	int mid = (start + end) / 2;
	long long result = max(func(start, mid), func(mid + 1, end));

	// �߰����� �����ϴ� ���
	int left = mid;
	int right = mid + 1;

	long long sum = arr[left] + arr[right];
	long long minVal = min(arr[left], arr[right]);

	result = max(result, sum * minVal);

	while (left > start || right < end) {
		// �߾ӿ��� �����ʰ� �߰��ϱ�
		if (right < end && (left == start || arr[left - 1] < arr[right + 1])) {
			sum += arr[++right];
			minVal = min(minVal, (long long)arr[right]);
		}
		// �߾ӿ��� ���ʰ� �߰��ϱ�
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