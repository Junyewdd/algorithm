#include <iostream>
using namespace std;
int arr[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << arr[b] - arr[a - 1]<<'\n';
	}
}