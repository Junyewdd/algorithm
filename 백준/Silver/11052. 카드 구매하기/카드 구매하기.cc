#include <iostream>
#include <algorithm>
using namespace std;
int card[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	card[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
		int max = 0, sum = 0;
		for (int j = 1; j <= (i / 2 + 1); j++) {
			sum = card[j] + card[i - j];
			if (sum > max)max = sum;
		}
		if(max>card[i])card[i] = max;
	}
	cout << card[n];
}