#include <iostream>
#include <string.h>
using namespace std;
char map[101][101];
bool visit[101][101];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, -1, 0, 1 };
int t, h, w;

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx < 0 || xx >= w || yy<0 || yy>=h)continue;
		if (map[yy][xx] != '#' || visit[yy][xx])continue;
		visit[yy][xx] = true;
		dfs(yy, xx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> h >> w;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < h; i++) {
			cin >> map[i];
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] != '#' || visit[i][j])continue;
				visit[i][j] = true;
				dfs(i, j);
				cnt++;
			}
		}
		cout << cnt<<endl;
	}
}