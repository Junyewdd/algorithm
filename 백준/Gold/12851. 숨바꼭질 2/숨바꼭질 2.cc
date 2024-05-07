#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int visited[100001];

int newPosition(int x, int i) {
	if (i == 0)return x + 1;
	if (i == 1)return x - 1;
	if (i == 2)return x * 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, cnt=0, min = -1;
	cin >> n >> k;

	queue <pair< int, int >> q;
	q.push({ n, 0 });
	visited[n] = 1;
	if (n == k) {
		cout << 0 << endl << 1;
		return 0;
	}
	while (!q.empty()) {
		int temp = q.front().first;
		int t = q.front().second;
		q.pop();
		if(temp ==k && !visited[temp]){
			min = t;
			cnt++;
		}
		else if (temp == k && t == min) {
			cnt++;
		}

		visited[temp] = true;

		for (int i = 0; i < 3; i++) {
			int nx = newPosition(temp, i);
			if (nx > 100000 || nx < 0 || visited[nx])continue;
			q.push({ nx, t + 1 });
		}
	}
	cout << min << '\n' << cnt;
}