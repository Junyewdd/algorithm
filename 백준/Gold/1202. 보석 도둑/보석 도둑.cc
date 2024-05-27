#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, less<int>> max_pq;
int n, k;
int p;
vector<pair<int, int>> gems;
vector<int> backpacks;

int fillBackpack(int index) {
	while (p < n && gems[p].first <= backpacks[index]) {
		max_pq.push(gems[p++].second);
	}

	if (max_pq.empty()) {
		return 0;
	}
	else {
		int ret = max_pq.top();
		max_pq.pop();
		return ret;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int w, v, c;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		gems.push_back({ w, v });
	}

	for (int i = 0; i < k; i++) {
		cin >> c;
		backpacks.push_back(c);
	}

	sort(gems.begin(), gems.end());
	sort(backpacks.begin(), backpacks.end());

	long long result = 0;

	for (int i = 0; i < k; i++) {
		result += (long long)fillBackpack(i);
	}

	cout << result;

	return 0;
}