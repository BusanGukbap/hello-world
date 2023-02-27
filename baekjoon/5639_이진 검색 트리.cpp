#include <iostream>

using namespace std;

// preorder 결과 -> postorder 결과 출력
int arr[40001];

typedef struct node {
	int data;
} node;

void postOrder(int start, int end) {
	if (start >= end)
		return;
	if (start == end - 1) {
		cout << arr[start] << '\n';
		return;
	}
	int index = start + 1;

	while (index < end) {
		if (arr[start] < arr[index])
			break;
		index++;
	}
		
	postOrder(start + 1, index);
	postOrder(index, end);
	cout << arr[start] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int temp;
	int idx = 1;
	while (cin >> temp) {
		arr[idx++] = temp;
	}

	postOrder(1, idx);

	return 0;
}