#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct edge {
    edge(int first_, int second_) : first(first_), second(second_), flow(0) {};
    int first; // куда
    int second; // flow
    int flow; // current flow
};

using namespace std;
//vector<vector<int>> flows;
vector<vector<edge>> cmax;
vector<int> dist;
vector<int> curr_edge;
int n_s;
int n_p;


const int INF = 1e9 + 7;

bool bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < cmax[curr].size(); ++i) {
            int to = cmax[curr][i].first;
            if (dist[to] == INF && cmax[curr][i].second > cmax[curr][i].flow) {
                q.push(to);
                dist[to] = dist[curr] + 1;
            }
        }
    }
    return dist[t] != INF;
}

vector<bool> used;

int dfs(int s, int t, int Cmin) {
    if (s == t) {
        return Cmin;
    }
    if (Cmin == 0) {
        return 0;
    }
    used[s] = true;
    for (int i = curr_edge[s]; i < cmax[s].size(); ++i) {
        int to = cmax[s][i].first;
        if (!used[to] && cmax[s][i].second > cmax[s][i].flow && dist[s] + 1 == dist[to]) {
            int delta = dfs(to, t, min(Cmin, cmax[s][i].second - cmax[s][i].flow));
            if (delta > 0) {
                cmax[s][i].flow += delta;
                int index;
                if (to == cmax.size() - 1 || to == cmax.size() - 2) {
                    index = s;
                } else if (s == cmax.size() - 2) {
                    index = cmax[to].size() - 2;
                } else if (s == cmax.size() - 1) {
                    index = cmax[to].size() - 1;
                } else if (s <= n_p - 1) {
                    index = s;
                } else {
                    index = s - n_p;
                }
                cmax[to][index].flow -= delta;
                return delta;
            }
        }
        curr_edge[s]++;
    }
    return 0;
}

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < cmax[v].size(); ++i) {
        int to = cmax[v][i].first;
        if (!used[to] && cmax[v][i].second > cmax[v][i].flow) {
            dfs(to);
        }
    }
}


int main() {
    string s, p;
    cin >> s >> p;

    int ones_in_s = 0;
    int zeros_in_s = 0;
    int ones_in_p = 0;
    int zeros_in_p = 0;
    n_p = 0;
    n_s = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            zeros_in_s++;
        } else if (s[i] == '1') {
            ones_in_s++;
        } else {
            n_s++;
        }
    }

    for (int  i = 0; i < p.size(); ++i) {
        if (p[i] == '0') {
            zeros_in_p++;
        } else if (p[i] == '1') {
            ones_in_p++;
        } else {
            n_p++;
        }
    }

    int n = n_p + n_s + 2;
//    flows.assign(n, vector<int>(n, 0));
    cmax.resize(n);


    for (int i = 0; i < n_p; ++i) {
        int curr = n_p;
        for (int j = 0; j < n_s; ++j) {
            cmax[i].push_back(edge(curr, 0));
            curr++;
        }
        cmax[i].push_back(edge(n - 2, 0)); // 0
        cmax[i].push_back(edge(n - 1, 0)); // 1
    }

    for (int i = n_p; i < n_p + n_s; ++i) {
        int curr = 0;
        for (int j = 0; j < n_p; ++j) {
            cmax[i].push_back(edge(curr, 0));
            curr++;
        }
        cmax[i].push_back(edge(n - 2, 0)); // 0
        cmax[i].push_back(edge(n - 1, 0)); // 1
    }

    cmax[n - 2].assign(n, edge(0, 0));
    cmax[n - 1].assign(n, edge(0, 0));

    int current_number_of_none_in_s = 0;
    int current_number_of_none_in_p = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        current_number_of_none_in_p = 0;
        for (int j = 0; j < p.size(); ++j) {
            if (s[i] == '?' && p[j] == '?' && i - j >= 0 && i + p.size() - j <= s.size()) {
                cmax[n_p + current_number_of_none_in_s][current_number_of_none_in_p].second++;
                cmax[current_number_of_none_in_p][current_number_of_none_in_s].second++;
            }
            if (s[i] == '0' && p[j] == '1' && i - j >= 0 && i + p.size() - j <= s.size()) {
                ans++;
            }
            if (s[i] == '1' && p[j] == '0' && i - j >= 0 && i + p.size() - j <= s.size()) {
                ans++;
            }
            if (s[i] == '?') {
                if (p[j] == '0' && i - j >= 0 && i + p.size() - j <= s.size()) {
                    cmax[n_p + current_number_of_none_in_s][n_p].second++;
                    cmax[n - 2][n_p + current_number_of_none_in_s].second++;
                    cmax[n - 2][n_p + current_number_of_none_in_s].first = current_number_of_none_in_s + n_p;
                } else if (p[j] == '1' && i - j >= 0 && i + p.size() - j <= s.size()) {
                    cmax[n_p + current_number_of_none_in_s][n_p + 1].second++;
                    cmax[n - 1][n_p + current_number_of_none_in_s].second++;
                    cmax[n - 1][n_p + current_number_of_none_in_s].first = current_number_of_none_in_s + n_p;
                }
            }

            if (p[j] == '?') {
                if (s[i] == '0' && i - j >= 0 && i + p.size() - j <= s.size()) {
                    cmax[current_number_of_none_in_p][n_s].second++;
                    cmax[n - 2][current_number_of_none_in_p].second++;
                    cmax[n - 2][current_number_of_none_in_p].first = current_number_of_none_in_p;
                } else if (s[i] == '1' && i - j >= 0 && i + p.size() - j <= s.size()) {
                    cmax[current_number_of_none_in_p][n_s + 1].second++;
                    cmax[n - 1][current_number_of_none_in_p].second++;
                    cmax[n - 1][current_number_of_none_in_p].first = current_number_of_none_in_p;
                }
                current_number_of_none_in_p++;
            }
        }
        if (s[i] == '?') {
            current_number_of_none_in_s++;
        }
    }

    int flow = 0;
    curr_edge.assign(n, 0);
    dist.clear();
    dist.assign(n, INF);
    while (bfs(n - 2, n - 1)) {
        curr_edge.assign(n, 0);
        used.clear();
        used.assign(n, false);
        int path = dfs(n - 2, n - 1, INF);
        while(path) {
            flow += path;
            used.clear();
            used.assign(n, false);
            path = dfs(n - 2, n - 1, INF);
        }
        dist.clear();
        dist.assign(n, INF);
    }

    ans += flow;
//    cout << flow << endl;
    cout << ans << endl;

    used.clear();
    used.assign(n, false);
    dfs(n - 2);

    string p_ans = "";
    string s_ans = "";
    int curr_none_in_p = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] != '?') {
            p_ans += p[i];
        } else {
            if (used[curr_none_in_p] == true) {
                p_ans += '0';
            } else {
                p_ans += '1';
            }
            curr_none_in_p++;
        }
    }

    int curr_none_in_s = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '?') {
            s_ans += s[i];
        } else {
            if (used[n_p + curr_none_in_s] == true) {
                s_ans += '0';
            } else {
                s_ans += '1';
            }
            curr_none_in_s++;
        }
    }

    cout << s_ans << endl << p_ans << endl;
    return 0;
}




for (int i = 0; i < n; ++