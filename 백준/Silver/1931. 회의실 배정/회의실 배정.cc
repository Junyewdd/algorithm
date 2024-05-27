#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> meeting;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, start, finish, cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> finish >> start;
		meeting.push_back(make_pair(start, finish));
	}
	sort(meeting.begin(), meeting.end());

	int end = meeting[0].first;
	for (int i = 1; i < n; i++) {
		if (end <= meeting[i].second) {
			cnt++;
			end = meeting[i].first;
		}
	}
	cout << cnt;
}