#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;
	
int T, K, M;

int skill[100][5];
int l[5];
int head[50];
int headIdx;
int shirt[50];
int shirtIdx;
int pants[50];
int pantsIdx;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T >> K;

	for (int i = 0; i < 5; i++) {
		cin >> l[i];
		for (int j = 0; j < l[i]; j++) {
			cin >> skill[j][i];
		}
	}

	cin >> headIdx;
	for (int i = 0; i < headIdx; i++)
		cin >> head[i];
	






	return 0;
}