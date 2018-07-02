#include <iostream>
#include <vector>
#include <string>
#include <queue>


using namespace std;
int deg[300007];
int result[300007];
int n;
int m;

//1 draw 2 second 3 first

void bfs(vector<vector<int>>& g) {
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) {
            q.push(i);
            result[i] = 2;
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < g[curr].size(); ++i) {
            int to = g[curr][i];
            if (result[to] == 1) {
                if (result[curr] == 2) {
                    q.push(to);
                    result[to] = 3;
                } else if (result[curr] == 3) {
                    deg[to]--;
                    if (deg[to] == 0) {
                        q.push(to);
                        result[to] = 2;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n) {
        cin >> m;
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            deg[i] = 0;
            result[i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            int from, to;
            cin >> from >> to;
            from--;
            to--;
            g[to].push_back(from);
            deg[from]++;
        }
        
        bfs(g);

        for (int i = 0; i < n; ++i) {
            string ans;
            if (result[i] == 1) {
                ans = "DRAW";
            } else if (result[i] == 2){
                ans = "SECOND";
            } else {
                ans = "FIRST";
            }
            cout << ans << std::endl;
        }
        cout << endl;
    }

    return 0;
}
