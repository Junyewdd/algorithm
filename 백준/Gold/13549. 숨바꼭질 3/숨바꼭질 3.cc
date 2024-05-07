#include <iostream>
#include <deque>
using namespace std;
int visited[100001];
int n, k, cnt = 0, min = -1;

int newPosition(int x, int i) {
	if (i == 0)return x - 1;
	if (i == 1)return x + 1;
}

int bfs() {
	deque<int>dq;
	dq.push_back(n);
	visited[n] = 1;

	while (!dq.empty()) {
		int x = dq.front();
		dq.pop_front();

		if (x == k) {
			return visited[k] - 1;
		}

		if (x * 2 <= 100000 && !visited[x * 2]) {
			dq.push_front(x * 2);
			visited[x * 2] = visited[x];
		}
		for (int i = 0; i < 2; i++) {
			int nx = newPosition(x, i);
			if (0<= nx &&nx <= 100000 && !visited[nx]) {
				dq.push_back(nx);
				visited[nx] = visited[x] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	int result = bfs();
	cout << result;
}