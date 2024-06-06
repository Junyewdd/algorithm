#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<double, pair<int, int>> T;
int n, m;
vector<pair<int, int>> coord; // 우주신들 좌표
vector<pair<int, int>> connect; // 기존 연결
vector<T> v;
int parent[100001];
double ans;

int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

double calcDist(int x1, int y1, int x2, int y2) {
    double dx = pow(x1 - x2, 2);
    double dy = pow(y1 - y2, 2);
    return sqrt(dx + dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 우주신들의 좌표 입력
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        coord.push_back({ a, b });
    }

    // 이미 연결된 통로 입력
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        connect.push_back({ a, b });
        unionParent(a, b); // 기존 연결을 union으로 미리 처리
    }

    // 모든 가능한 간선 생성
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = calcDist(coord[i].first, coord[i].second, coord[j].first, coord[j].second);
            v.push_back({ dist, {i + 1, j + 1} });
        }
    }

    // 간선들을 거리 순으로 정렬
    sort(v.begin(), v.end());

    // 크루스칼
    for (int i = 0; i < v.size(); i++) {
        int n1 = v[i].second.first;
        int n2 = v[i].second.second;
        double dist = v[i].first;

        if (findParent(n1) != findParent(n2)) {
            unionParent(n1, n2);
            ans += dist;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << ans << endl;

    return 0;
}
