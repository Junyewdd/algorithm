#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool** visited;
int n, **map;
int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

bool bfs();

int main() {
	cin >> n;
	map = new int* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
		visited[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			visited[i][j] = false;
		}
	}
	if (bfs())cout << "HaruHaru";
	else cout << "Hing";
}

bool bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[x][y] == -1)
			return true;
		
		for (int i = 0; i < 2; i++) {
			int xx = x + dx[i] * map[x][y];
			int yy = y + dy[i] * map[x][y];

			if (0 <= xx && xx <= n - 1 && 0 <= yy && yy <= n - 1) {
				if (!visited[xx][yy]) {
					visited[xx][yy] = true;
					q.push({ xx, yy });
				}
			}
		}
	}
	return false;
}