#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    long long total = 1;
    for (long long i = 1; i <= n; i++) {
        total *= i;
    }
    cout << total;
    return 0;
}