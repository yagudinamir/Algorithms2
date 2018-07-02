#include <iostream>
#include <vector>

using namespace std;

long long MOD = (1 << 30) + 1;

int get_bit(long long pr, int n) {
    return (pr & (1 << n)) >> n;
}

int main() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }

    long long t = 1 << (n + 1);

    if (m == 1) {
        cout << (1 << n);
        return 0;
    }

    vector<long long> prev(t, 0);
    vector<long long> next(t, 0);
    for (long long i = 0; i < t; ++i) {
        prev[i] = 1;
    }

    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            for (long long k = 0; k < t; ++k) {
                if (j != n - 1) {
                    if (get_bit(k, j) == get_bit(k, j + 1) && get_bit(k, j + 1) == get_bit(k, j + 2) && get_bit(k, j) == get_bit(k, j + 2)) {
                        next[k xor (1 << (j + 1))] += prev[k];
                        next[k xor (1 << (j + 1))] %= MOD;
                    } else {
                        next[k] += prev[k];
                        next[k] %= MOD;
                        next[k xor (1 << (j + 1))] += prev[k];
                        next[k xor (1 << (j + 1))] %= MOD;
                    }
                } else {
                    if (i == m - 2)
                        continue;
                    next[((k << 1) + 1) & (t - 1)] += prev[k];
                    next[((k << 1) + 1) & (t - 1)] %= MOD;
                    next[(k << 1) & (t - 1)] += prev[k];
                    next[(k << 1) & (t - 1)] %= MOD;
                }
            }
            if (i == m - 2 && j == n - 1)
                break;
            prev = next;
            next.assign(t, 0);
        }
    }

    long long ans = 0;

    for (long long i = 0; i < t; ++i) {
        ans += prev[i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}