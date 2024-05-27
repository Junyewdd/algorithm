#include <stdio.h>
#pragma warning (disable : 4996)
int main() {
	int n, q = 0, cnt = 0;
	scanf("%d", &n);
	q = n / 5;
	while (1) {
		if (q == 0 && n % 3 != 0) {
			cnt = -1;
			break;
		}
		if (n % 5 == 0) {
			cnt = q;
			break;
		}
		else if ((n - q * 5) % 3)
			q -= 1;
		else if (!((n - q * 5) % 3)) {
			cnt = q + (n - q * 5) / 3;
			break;
		}

	}
	printf("%d", cnt);
}