#include <iostream>
#include <queue> //bfs
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g[1001];
int bVisited[1001], dVisited[1001];
queue<int> q;

void bfs(int v);
void dfs(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, v, a, b;
	cin >> n >> m >> v;	

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end());
	dfs(v);
	cout << endl;
	bfs(v);

}

void bfs(int v) {
	q.push(v);
	bVisited[v] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cout << temp<<" ";
		bVisited[temp] = 1;
		int size = g[temp].size();
		for (int i = 0; i < size; i++) {
			int k = g[temp][i];
			if (!bVisited[k]) {
				bVisited[k] = 1;
				q.push(k);
			}
		}
	}
}

void dfs(int v) {
	cout << v << " ";
	dVisited[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int k = g[v][i];
		if (!dVisited[k]) {
			dfs(k);
		}
	}
}