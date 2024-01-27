#include <iostream>
#include <stack>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;
char** map;
bool** visited;

int dfs(int currentX, int currentY);

int main() {
	int currentX=0, currentY=0;
	scanf("%d %d", &n, &m);
	map = new char* [n];
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new char[m];
		visited[i] = new bool[m];
		scanf("%s", map[i]);
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
			if (map[i][j] == 'I') {
				currentX = i;
				currentY = j;
			}
		}
	}

	int meet = dfs(currentX, currentY);
	if (meet == 0)cout << "TT";
	else cout << meet;

	return 0;
}

int dfs(int currentX, int currentY) {
	stack<pair<int, int>> s;
	int meet = 0;
	s.push({ currentX, currentY });
	visited[currentX][currentY] = true;

	while (!s.empty()) {
		int x = s.top().first;
		int y = s.top().second;
		s.pop();
		
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (0 <= xx && xx < n && 0 <= yy && yy < m) {
				if (visited[xx][yy])continue;
				if (map[xx][yy] == 'X')continue;
				
				visited[xx][yy] = true;
				s.push({ xx, yy });
				
				if (map[xx][yy] == 'P') {
					meet++;
				}
			}
		}
	}
	return meet;
}