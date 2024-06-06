#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int>>T;
int V, E;
vector<T> v;
int parent[100001];
int ans;

int findParent(int x) {
	if (parent[x] == x)return x;
	
	parent[x] = findParent(parent[x]);
	return parent[x];
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c, {a, b} });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	//크루스칼
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		T temp = v[i];
		int cost = temp.first;
		int now = temp.second.first;
		int next = temp.second.second;

		if (findParent(now) != findParent(next)) { //서로 다른 루트인지
			unionParent(now, next);
			ans += cost;
			if (++cnt == V - 1)break; // 트리 완성
		}
	}
	cout << ans << endl;
}