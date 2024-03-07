#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector <vector<int>> graph;
vector<int> dist;
vector<int> result;

void bfs(int x) {
	dist[x] = 0;
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			if (dist[next] == -1) {
				dist[next] = dist[current] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k, x;
	cin >> n >> m >> k >> x;
	graph = vector<vector<int>>(n + 1);
	dist = vector<int>(n + 1, -1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	bfs(x);

	for (int i = 1; i <= n; i++) {
		if (dist[i] == k)result.push_back(i);
	}
	if (result.size() == 0)cout << "-1";
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
		}
	}
}