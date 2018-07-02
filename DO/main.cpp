#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::min;
using std::pair;

const int INF = 1e7 + 6;

void tree_build(const vector<int>& data, vector<pair<int, bool>>& tree, int node, int tl, int tr) {
    /**
     * Building tree requirsevely, since it is bulding from the root,
     * it not neccessary (possible to build from the bottom)
     */
    if (tl == tr) {
        return;
    }
    if (tl == tr - 1) {
        tree[node].first = data[tl];
        tree[node].second = false;
        return;
    }
    int tm = (tl + tr) / 2;
    int left = (node << 1) + 1;
    int right = (node << 1) + 2;
    tree_build(data, tree, left, tl, tm);
    tree_build(data, tree, right, tm, tr);
    tree[node].first = min(tree[left].first, tree[right].first);
    tree[node].second = false;
}

void push(vector<pair<int, bool>>& tree, int node, int tl, int tr) {
    if (tl == tr) {
        return;
    }
    if (tl == tr - 1) {
        return;
    }
    //if it is assigned
    if (tree[node].second) {
        int left = (node << 1) + 1;
        int right = (node << 1) + 2;
        tree[left].first = tree[node].first;
        tree[right].first = tree[node].first;
        tree[left].second = true;
        tree[right].second = true;
    }
}

void color_full_segment(vector<pair<int, bool>>& tree, int node, int tl, int tr, int l, int r, int color) {
    if (tr <= l || tl >= r) {
        return;
    }
    if (l <= tl && tr <= r) {
        tree[node].second = true;
        tree[node].first = color;
        return;
    }
    push(tree, node, tl, tr);
    int tm = (tl + tr) / 2;
    int left = (node << 1) + 1;
    int right = (node << 1) + 2;
    color_full_segment(tree, left, tl, tm, l, r, color);
    color_full_segment(tree, right, tm, tr, l, r, color);
    tree[node].first = min(tree[left].first, tree[right].first);
    tree[node].second = false;
}

int rmq_min(vector<pair<int, bool>>& tree, int node, int tl, int tr, int l, int r) {
    /**
     * RMQ minimum from the upper root node, down to the lists
     * it is necessary, since there are massive operations
     */
    if (tr <= l || r <= tl) {
        return INF;
    }

    if (l <= tl && r >= tr) {
        return tree[node].first;
    }
    push(tree, node, tl, tr);
    int tm = (tl + tr) / 2;
    int left = (node << 1) + 1;
    int right = (node << 1) + 2;
    int left_min = rmq_min(tree, left, tl, tm, l, r);
    int right_min = rmq_min(tree, right, tm, tr, l, r);
    return min(left_min, right_min);
}

int main() {
    int n;
    cin >> n;
    int size = 1;
    while (size < n) {
        size = size << 1;
    }

    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        data[i] = a + b + c;
    }

    while (data.size() < size) {
        data.push_back(INF);
    }

    vector<pair<int, bool>> tree(2 * size);
    tree_build(data, tree, 0, 0, size);

    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int c, d, r, g, b, e, f;
        cin >> c >> d >> r >> g >> b >> e >> f;
        color_full_segment(tree, 0, 0, size, c, d + 1, r + g + b);
        cout << rmq_min(tree, 0, 0, size, e, f + 1) << "\n";
    }

    return 0;
}

