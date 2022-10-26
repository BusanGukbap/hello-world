#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

bool twitch[101];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> twitch[i];
	}

	int L;
	cin >> L;
	int gender, index;
	for (int i = 0; i < L; i++) {
		cin >> gender >> index;
		if (gender == 1) {
			for (int i = 1; i * index <= N; i++) {
				if (twitch[i * index])
					twitch[i * index] = 0;
				else
					twitch[i * index] = 1;
			}
		}
		else if (gender == 2) {
			int cnt = 0;
			while ((index-cnt > 0) && (index+cnt <= N)) {
				if (twitch[index - cnt] == twitch[index + cnt]) {
					if (twitch[index - cnt])
						twitch[index - cnt] = twitch[index + cnt] = 0;
					else
						twitch[index - cnt] = twitch[index + cnt] = 1;
					cnt++;
				}
				else
					break;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (i % 20 == 1 && i != 1)
			cout << '\n';
		cout << twitch[i] << " ";
	}

	return 0;
}