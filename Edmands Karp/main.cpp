#include <iostream>
#include <vector>
#include <queue>
#include <cassert>


using namespace std;

const int INF = 1e9;

vector<vector<int>> f;
vector<vector<pair<int, int>>> c;

int bfs(int v, int t) {
    vector<bool> used(f.size(), false);
    vector<int> parent(f.size());
    vector<int> min_edge_on_path(f.size());

    queue<int> q;
    q.push(v);
    used[v] = true;
    parent[v] = -1;
    min_edge_on_path[v] = INF;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < c[curr].size(); ++i) {
            int to = c[curr][i].first;
            int curr_weight = c[curr][i].second;
            if (!used[to] && curr_weight > f[curr][to]) {
                used[to] = true;
                q.push(to);
                parent[to] = curr;
                min_edge_on_path[to] = min(min_edge_on_path[curr], curr_weight - f[curr][to]);
            }
        }
    }

    if (!used[t]) {
        return 0;
    }

    int min_edge = min_edge_on_path[t];
    for (int p = t ; parent[p] != -1; p = parent[p]) {
        f[parent[p]][p] += min_edge;
        f[p][parent[p]] -= min_edge;
    }

    min_edge_on_path.clear();
    used.clear();
    parent.clear();
    while (!q.empty())
        q.pop();

    return min_edge;
}

int main () {
    int n, m;
    cin >> n >> m;

    f.assign(n, vector<int>(n, 0));
    c.resize(n);

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        from--;
        to--;
        if (from != to) {
            c[from].push_back(make_pair(to, weight));
            c[to].push_back(make_pair(from, 0));
        }
    }

    long long stream = 0;

    while (true) {
        int path;
        path = bfs(0, n - 1);
        if (path == 0)
            break;
        stream += path;
    }

    cout << stream;

    return 0;
}