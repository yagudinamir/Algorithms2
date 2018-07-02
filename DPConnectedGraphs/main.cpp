#include <iostream>
#include <vector>

using namespace std;
int n;
long long MOD = 1e9 + 7;
vector<long long> d;
vector<vector<long long>> c;
vector<long long> twos;


long long CalculateDynamics(int n) {
    for (int i = 0; i <= n; ++i) {
        c[0][i] = 0;
    }
    for (int i = 0; i <= n; ++i) {
        c[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
//    for (int i = 0; i <= n; ++i) {
//        for (int j = 0; j <= n; ++j) {
//            cout << c[i][j] << " ";
//        }
//        cout << endl;
//    }
    twos[0] = 1;
    for (int i = 1; i <= n; ++i) {
        twos[i] = (twos[i - 1] * 2) % MOD;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < i; ++j) {
            d[i + 1] += ((((d[j] * (twos[j] - 1) % MOD) * (d[i + 1 - j])) % MOD) * c[i - 1][j - 1]) % MOD;
            d[i + 1] = d[i + 1] % MOD;
        }
        d[i + 1] += (d[i] * (twos[i] - 1)) % MOD;
        d[i + 1] = d[i + 1] % MOD;
    }
    return d[n];
}

int main() {
    cin >> n;
    d.assign(n + 1, 0);
    c.resize(n + 1, vector<long long>(n + 1));
    twos.resize(n + 1);
    d[1] = 1;
    cout << CalculateDynamics(n);

    return 0;
}