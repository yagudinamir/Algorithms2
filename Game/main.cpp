#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<bool>> dp;
    dp.resize(100005, vector<bool>(450));

    for (int i = 0; i < 100001; ++i) {
        for (int j = 1; j < 448; ++j) {
            if (i == 0) {
                dp[i][j] = true;
                continue;
            }
            if (i < j) {
                dp[i][j] = true;
                continue;
            }
            if (j == 447) {
                dp[i][j] = true;
                continue;
            }
            if (i == j) {
                dp[i][j] = !dp[i - j][j];
                continue;
            }
            if (dp[i - j][j] || dp[i - j - 1][j + 1]) {
                dp[i][j] = false;
                continue;
            }
            dp[i][j] = true;
        }
    }
    int n;
    int curr = 1;
    while(cin >> n && n != 0) {
        string s;
        if (dp[n - 1][1]) {
            s = "First";
        } else {
            s = "Second";
        }
        cout << "Case #" << curr << ": " << s <<" player wins. \n";
        curr++;
    }

    return 0;
}

