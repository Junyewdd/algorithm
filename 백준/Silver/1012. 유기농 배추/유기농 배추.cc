#pragma warning (disable : 4996)
#include <stdio.h>
#include <queue>
using namespace std;
struct pp {
	int x, y;
};
queue <pp> q;
int map[52][52], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
void bfs(int sx, int sy, int m, int n) {
	q.push({ sx, sy });
	map[sy][sx] = 0;
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nextx = q.front().x + dx[i], nexty = q.front().y + dy[i];
			if (nextx<0 || nextx>=m || nexty<0 || nexty>=n)continue;
			if(map[nexty][nextx]){
				q.push({ nextx, nexty });
				map[nexty][nextx] = 0;
			}
		}
		q.pop();
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int m, n, k, a, b, cnt = 0;
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &a, &b);
			map[b][a] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {//m은 x
				if (map[i][j] == 0)continue;
				else { 
					cnt++;
					bfs(j, i, m, n); 
				}
			}
		}
		printf("%d\n", cnt);
	}
}