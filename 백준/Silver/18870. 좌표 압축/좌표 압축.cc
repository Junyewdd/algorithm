#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> ans(v);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (const auto& val : v) {
		auto it = lower_bound(ans.begin(), ans.end(), val);
		cout << distance(ans.begin(), it) << ' ';
	}
}