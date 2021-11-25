#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> root;

void make_set() {
    for (int i = 0; i <= N; i++) {
        root.push_back(i);
    }
}

int find(int x) {
    if (root[x] == x)
        return x;
    else
        return root[x] = find(root[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    root[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    make_set();
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> c >> a >> b;
        if (c == 1) {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if (c == 0) {
            Union(a, b);
        }
    }

    return 0;
}