#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	string str = "";
	int num;
	
	cin >> str;
	list<char> li(str.begin(), str.end());

	auto cursor = li.end();

	cin >> num;

	while (num--) {
		char command;

		cin >> command;
		if (command == 'L') {
			if (cursor != li.begin())
				cursor--;
		}
		else if (command == 'D') {
			if (cursor != li.end())
				cursor++;
		}
		else if (command == 'B') {
			if (cursor != li.begin()) {
				cursor--;
				cursor = li.erase(cursor);
			}
		}
		else if (command == 'P') {
			char alp;
			cin >> alp;

			li.insert(cursor, alp);
		}
	}

	for (cursor = li.begin(); cursor != li.end(); cursor++)
		cout << *cursor;
}