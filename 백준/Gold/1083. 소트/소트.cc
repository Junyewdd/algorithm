#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s, cnt, maxNum, maxIdx;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> s;

	for (int i = 0; i < n - 1 && s != 0; i++) {
		cnt = 0;
		maxNum = arr[i];
		maxIdx = i;

		//max인 곳 구하기
		for (int j = i + 1; j < n && cnt < s; j++, cnt++) {
			if (maxNum < arr[j]) {
				maxNum = arr[j];
				maxIdx = j;
			}
		}

		//swap 과정
		int k = maxIdx;
		if (maxIdx > i) {
			while (k != i) {
				int temp = arr[k];
				arr[k] = arr[k - 1];
				arr[k - 1] = temp;
				k--;
			}
		}
		s -= (maxIdx - i);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}