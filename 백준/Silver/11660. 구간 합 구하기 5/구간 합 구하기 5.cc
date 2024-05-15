#include <iostream>
using namespace std;
int arr[1025][1025];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {//y
		for (int j = 1; j <= n; j++) {//x
			cin >> arr[i][j];
			arr[i][j] += arr[i][j - 1];
		}
	}
	while (m--) {
		int x1, x2, y1, y2, sum = 0;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int i = y1; i <= y2; i++) {
			sum += arr[i][x2] - arr[i][x1 - 1];
		}
		cout << sum<<'\n';
	}	
}