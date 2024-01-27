#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, a;
	cin >> n;

	priority_queue<int> pq;
	
	while (n--) {
		cin >> a;
		if (a == 0) {
			if (pq.empty())cout << "-1" << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
			continue;
		}
		while (a--) {
			int temp;
			cin >> temp;
			pq.push(temp);
		}
	}
}