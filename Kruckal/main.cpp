#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;

int dsu_get(int v) {
    return v == p[v] ? v : p[v] = dsu_get(p[v]);
}

void dsu_unite(int a, int b) {
    a = dsu_get(a);
    b = dsu_get(b);
    if (rand() & 1) {
        swap(a, b);
    }
    if (a != b) {
        p[a] = b;
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        if (from == to) {
            continue;
        }
        from--;
        to--;
        edges.push_back(make_pair(weight, make_pair(from, to)));
    }

    sort(edges.begin(), edges.end());

    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int w = edges[i].first;
        if (dsu_get(a) != dsu_get(b)) {
            ans += w;
            dsu_unite(a, b);
        }
    }

    cout << ans;

    return 0;
}