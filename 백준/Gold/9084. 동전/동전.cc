#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int coin[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n; // 돈 종류
		for (int i = 1; i <= n; i++) {
			cin >> coin[i];
		}
		cin >> m; // 만들어야 하는 돈

		int dp[10001] = { 0, };
		dp[0] = 1;

		for (int i = 1; i <= n; i++) {//돈 종류
			for (int j = coin[i]; j <= m; j++) { // 만들어야 하는 돈
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[m] << endl;
	}
}