#include <iostream>
#include <algorithm>
using namespace std;
int dp[21][201];
int arr[21][2]; // 일 분량
int day, ch;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> day >> ch;

	for (int i = 1; i <= ch; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 1; i <= ch; i++) {
		for (int j = 0; j <= day; j++) {
			if (j - arr[i][0] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i][0]] + arr[i][1]);
			}
			dp[i][j] = max(dp[i - 1][j], dp[i][j]);
		}
	}
	cout << dp[ch][day];
}