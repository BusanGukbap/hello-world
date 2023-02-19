// Fenwick Tree
#include<iostream>

using namespace std;

typedef long long ll;

int N, M;
ll tree[100001];

void update(int idx, ll num) {
    while (idx <= N) {
        tree[idx] += num;
        idx += (idx & -idx);
    }
}

ll sum(int idx) {
    ll ans = 0;
    while (idx > 0) {
        ans += tree[idx];
        idx -= (idx & -idx);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll prev_num, now_num;

    cin >> N;
    
    cin >> prev_num;
    update(1, prev_num);
    for (int i = 2; i <= N; ++i) {
        cin >> now_num;
        update(i, now_num - prev_num);
        prev_num = now_num;
    }

    cin >> M;

    int num, i, j, x;
    ll k;
    while (M--) {
        cin >> num;
        if (num == 1) {
            cin >> i >> j >> k;
            update(i, k);
            update(j + 1, -k);
        }
        else {
            cin >> x;
            cout << sum(x) << '\n';
        }
    }

    return 0;
}