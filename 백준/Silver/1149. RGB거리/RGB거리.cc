#pragma warning (disable : 4996)
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int n, rem[3]={}, num[3]={};
	scanf("%d", &n);
	for (int i = 0; i < 3; i++) {
		scanf("%d", &rem[i]);
	}
	n--;
	while (n--) {
		
		for (int i = 0; i < 3; i++) {
			scanf("%d", &num[i]);
		}
		num[0] += min(rem[1], rem[2]);
		num[1] += min(rem[0], rem[2]);
		num[2] += min(rem[1], rem[0]);

		rem[0] = num[0];
		rem[1] = num[1];
		rem[2] = num[2];
	}
	int minimum=100000000;
	for (int i = 0; i < 3; i++) {
		if (minimum > num[i])minimum = num[i];
	}
	printf("%d", minimum);
}