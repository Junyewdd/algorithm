#include <iostream>
#include <string.h>
using namespace std;
int map[51][51];
int visited[51][51];
int w, h;
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 }, dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void dfs(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int nextX = x + dx[i], nextY = y + dy[i];
		if (nextX <= 0 || nextY <= 0 || nextX > w || nextY > h)continue;
		if (!visited[nextY][nextX] && map[nextY][nextX]) {
			visited[nextY][nextX] = 1;
			dfs(nextY, nextX);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> w >> h;
		if (!w && !h)break;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
			}
		}
		int cnt = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (!visited[i][j] && map[i][j]) {
					visited[i][j] = 1;
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		memset(visited, 0, sizeof(visited));
	}
}