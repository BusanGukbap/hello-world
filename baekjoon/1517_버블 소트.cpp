#include <iostream>

using namespace std;
long long ans = 0;
int N;
int A[500000];

void mergeSort(int arr[], int size) {
    if (size == 1) return;
    int mid = size / 2;
    mergeSort(arr, mid);
    mergeSort(arr + mid, size - mid);

    int* buf = new int[size];
    int i = 0, j = mid, k = 0;
    while (i < mid && j < size) {
        if (arr[i] <= arr[j])
            buf[k++] = arr[i++];
        else {
            buf[k++] = arr[j++];
            ans += (mid - i);
        }
    }
    while (i < mid)
        buf[k++] = arr[i++];
    while (j < size)
        buf[k++] = arr[j++];

    for (i = 0; i < size; ++i)
        arr[i] = buf[i];

    delete buf;
}

int main(int argc, char** argv) {

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    mergeSort(A, N);
    cout << ans;

    return 0;
}