#include <iostream>
#include <vector>

using namespace std;
int n;

bool is_adjacent(int a, int b) {
    int x = a xor b;
    int y = a xor ((b << 1) % (1 << n));
    int z = ((a << 1) % (1 << n)) xor b;
    x = ((1 << n) - 1) xor x;
    y = ((1 << n) - 1) xor y;
    z = ((1 << n) - 1) xor z;
    int ans = x & y & z;
    if (ans >= 2) {
        return false;
    } else {
        return true;
    }
}


int main() {
    int m;
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    long long t = 1 << n;
    vector<vector<long long>> a(m, vector<long long>((t) + 5, 0));
    vector<vector<int>> dp((t) + 5, vector<int>((t) + 5));
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            if (i == 3 && j == 3) {

            }
            if (is_adjacent(i , j)) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < t; ++i) {
        a[0][i] = 1;
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < t; ++j) {
            for (int k = 0; k < t; ++k) {
                a[i][j] += a[i - 1][k] *  dp[k][j];
            }
        }
    }

    long long ans = 0;

    for (int i = 0; i < t; ++i) {
        ans += a[m - 1][i];
    }

    cout << ans;

    return 0;
}