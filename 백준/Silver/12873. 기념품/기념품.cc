#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    auto it = v.begin();

    for (unsigned long long i = 1; i <= n; i++) {
        unsigned long long target = (i * i * i - 1) % v.size();
        for (int j = 0; j < target; j++) {
            it++;
            if (it == v.end())it = v.begin();
        }

        it = v.erase(it);

        if (it == v.end()) {
            it = v.begin();
        }
    }
    cout << *v.begin() << endl;

    return 0;
}