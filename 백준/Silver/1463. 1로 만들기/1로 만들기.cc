#include <stdio.h>
#pragma warning (disable : 4996)
#define min(x, y) (x) < (y) ? (x) : (y)
int d[1000001];
int main() {
	int n;
	scanf("%d", &n);
	d[0] = 0, d[1] = 0;
	d[2] = 1;
	for (int i = 3; i <= n; i++) {
		d[i] = 0xFFFFFFF;
	}

	
	for (int i = 1; i <= n; i++) {
		if (3 * i <= n)d[3 * i] = min(d[i] + 1, d[3 * i]);
		if (2 * i <= n)d[2 * i] = min(d[i] + 1, d[2 * i]);
		if (i + 1 <= n)d[i + 1] = min(d[i] + 1, d[i + 1]);
	}
	printf("%d", d[n]);
}