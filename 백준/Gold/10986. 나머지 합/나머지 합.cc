#include <iostream>
using namespace std;
long long arr[1000001], cnt[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] = (arr[i] + arr[i - 1]) % m;
		cnt[arr[i]]++;
	}

	long long ans = cnt[0];
	for (int i = 0; i < m; i++) {
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << ans;
}