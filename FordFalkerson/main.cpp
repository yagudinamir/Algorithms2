#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> f;
vector<vector<pair<int, int>>> c;
vector<bool> used;

int dfs(int v, int Cmin, int t) {
    used[v] = true;
    if (v == t) {
        return Cmin;
    }

    for (int i = 0; i < c[v].size(); ++i) {
        int to = c[v][i].first;
        if (!used[to] && c[v][i].second - f[v][to] > 0) {
            int delta = dfs(to, min(Cmin, c[v][i].second - f[v][to]), t);
            if (delta > 0) {
                f[v][to] += delta;
                f[to][v] -= delta;
                return delta;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    used.assign(n, false);
    f.assign(n, vector<int>(n, 0));
    c.resize(n);

    for (int i = 0; i < m; ++i) {
        int from, to, max_c;
        cin >> from >> to >> max_c;
        from--;
        to--;
        if (from != to) {
            c[from].push_back(make_pair(to, max_c));
            c[to].push_back(make_pair(from, 0));
        }
    }

    int stream = 0;

    int path = dfs(0, 1e9, n - 1);
    while (path > 0) {
        stream += path;
        used.assign(n, false);
        path = dfs(0, 1e9, n -1);
    }

    cout << stream;

    return 0;
}