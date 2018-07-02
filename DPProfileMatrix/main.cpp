#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;
long long MOD;

vector<vector<unsigned long long>> ans(10, vector<unsigned long long>(10));
void mult(vector<vector<unsigned long long>>& f, vector<vector<unsigned long long>>& s) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ans[i][j] = 0;
            for (int k = 0; k < 10; ++k) {
                ans[i][j] += f[i][k] * s[k][j];
                ans[i][j] = ans[i][j] % MOD;
            }
        }
    }
    s = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    clock_t y = clock();
    int t;
    cin >> t;
    for (int o = 0; o < t; ++o) {
        unsigned long long n;
        int l, r;
        cin >> n >> l >> r >> MOD;
        if (n == 1) {
            int a = 10 % MOD;
            cout << a << endl;
            continue;
        }
        vector<vector<unsigned long long>> dp(10, vector<unsigned long long>(10));
        vector<vector<unsigned long long>> m(10, vector<unsigned long long>(10));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if ( l <= abs(i - j) && abs(i - j) <= r) {
                    m[i][j] = 1;
                } else {
                    m[i][j] = 0;
                }
                if (i == j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        n = n - 1;
        while(n) {
            if (n & 1) {
                n = n - 1;
                mult(m, dp);
            } else {
                n = n / 2;
                mult(m, m);
            }
        }
        unsigned long long a = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = 1; j < 10; ++j) {
                a += dp[i][j];
                a = a % MOD;
            }
        }
        cout << a << endl;
    }
    return 0;
}