#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string arr[1000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	int l = s.length();
	for (int i = 0; i < l; i++) {
		arr[i] = s.substr(i, l - i);
	}
	sort(arr, arr + l);
	for (int i = 0; i < l; i++) {
		cout << arr[i]<<endl;
	}
}