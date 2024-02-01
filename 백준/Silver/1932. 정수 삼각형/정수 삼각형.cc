#include <iostream>
#include <algorithm>
using namespace std;

int triangle[501][501];

int main() {
	int n, m = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int temp;
			cin >> temp;
			triangle[i][j] = temp + max(triangle[i-1][j-1], triangle[i-1][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (m < triangle[n][i])m = triangle[n][i];
	}
	cout << m;
}