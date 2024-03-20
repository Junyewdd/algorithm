#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int map[500][500];
int dp[500][500];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = {0, -1, 0, 1};

int search(int x, int y, int size);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, search(j, i, n));
		}
	}
	cout << ans;
}

int search(int x, int y, int size) {
	if (dp[y][x]) return dp[y][x];

	dp[y][x] = 1;
	int now = map[y][x];
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx < 0 || xx >= size || yy < 0 || yy >= size)continue; // map 벗어나면 건너뜀
		
		int next = map[yy][xx];
		if (now >= next)continue; // 작으면 건너뜀

		dp[y][x] = max(dp[y][x], search(xx, yy, size) + 1);
	}
	return dp[y][x];
}