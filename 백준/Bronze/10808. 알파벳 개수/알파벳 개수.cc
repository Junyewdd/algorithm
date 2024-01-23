#include <iostream>
#include <vector>

using namespace std;


int main() {
    string s;
    cin >> s;

    vector<int> v(26);

    for (auto c : s) {
        int temp = c - 'a';
        v[temp]++;
    }
    for (auto i : v) {
        cout << i<<" ";
    }
}