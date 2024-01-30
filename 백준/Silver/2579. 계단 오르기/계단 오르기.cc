#include <stdio.h>
#pragma warning (disable : 4996)
#define max(a,b) (a)>(b)?(a):(b)


int main() {

	int d[310] = {}, s[310]={0};
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &s[i]);
	d[0] = 0;
	d[1] = s[1];
	d[2] = s[1] + s[2];
	for (int i = 3; i <= n; i++) {
		//d[n]=d[n-3]+s[n-1]+s[n]
		//d[n]=d[n-2]+s[n]
		d[i] = max(d[i - 3] + s[i - 1] + s[i], d[i-2]+s[i]);
	}
	printf("%d", d[n]);
}
