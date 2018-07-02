#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 1e7 + 6;

vector<vector<pair<int, int>>> sparse_table;
int minimal(int l, int r) {
    if (r < l)
        return INF;
    int t = static_cast<int>(log2(r - l + 1));
    return min(sparse_table[t][l].first, sparse_table[t][r - (1 << t) + 1].first);
}

int main() {
    int n, m;
    cin >> n >> m;
    int height = static_cast<int>(log2(n));
    sparse_table.resize(height + 1, vector<pair<int, int>>(n));
    for (size_t i = 0; i < n; ++i) {
        cin >> sparse_table[0][i].first;
        sparse_table[0][i].second = i;
    }

    for (size_t i = 1; i <= height; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if ((j + (1 << i) - 1) <= n - 1) {
                if (sparse_table[i - 1][j].first < sparse_table[i - 1][j + (1 << (i - 1))].first) {
                    sparse_table[i][j].first = sparse_table[i - 1][j].first;
                    sparse_table[i][j].second = sparse_table[i - 1][j].second;
                } else {
                    sparse_table[i][j].first = sparse_table[i - 1][j + (1 << (i - 1))].first;
                    sparse_table[i][j].second = sparse_table[i - 1][j + (1 << (i - 1))].second;
                }
            } else {
                continue;
            }
        }
    }

    for (size_t i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        int t = static_cast<int>(log2(r - l + 1));
        int min_index;
        if (sparse_table[t][l].first < sparse_table[t][r - (1 << t) + 1].first) {
            min_index = sparse_table[t][l].second;
        } else {
            min_index = sparse_table[t][r - (1 << t) + 1].second;
        }
        cout << min(minimal(l, min_index - 1), minimal(min_index + 1, r)) << endl;
    }

    return 0;
}