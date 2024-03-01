#include <iostream>
#include <algorithm>
using namespace std;
int result[10];
int main() {
	int n;
	cin >> n;
	for (int i = 0; n != 0; i++) {
		result[n%10]++;
		n /= 10;
	}
	for (int i = 9; i >= 0; i--) {
		while (result[i] != 0) {
			cout << i;
			result[i]--;
		}
	}
}