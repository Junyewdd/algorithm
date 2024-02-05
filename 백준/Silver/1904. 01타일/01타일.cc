#include <iostream>
#define mod 15746
using namespace std;
int arr[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i <= n; i++)
		arr[i] = (arr[i - 2] + arr[i - 1]) % mod;
	cout << arr[n];
}