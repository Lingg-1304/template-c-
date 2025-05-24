#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;
const int K = 101;
const int M = 1e9 + 7;
int f[N][K];
int main() {
	f[0][0] = 1;
	for (int i = 1; i < N; ++i) f[i][0] = 0;
	for (int j = 1; j < K; ++j) {
		int ans = 1;
		f[0][j] = 1;
		for (int i = 1; i < j; ++i) {
			f[i][j] = ans;
			ans = (ans + f[i][j]) % M;
		}
		for (int i = j; i < N; ++i) {
			f[i][j] = ans;
			ans = (ans - f[i - j][j] + M) % M;
			ans = (ans + f[i][j]) % M;
		}
	}
	int t=1;
	while (t--) {
		int n, k; cin >> n >> k;
		cout << f[n][k] << '\n';
	}
	return 0;
}
