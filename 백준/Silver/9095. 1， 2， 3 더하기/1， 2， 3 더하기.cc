#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int d[12];
		int n;
		scanf("%d", &n);
		d[1] = 1, d[2] = 2, d[3]=4;
		for (int i = 4; i <= n; i++) {
			d[i] = d[i - 3] + d[i - 2] + d[i - 1];
		}
		printf("%d\n", d[n]);
	}
}