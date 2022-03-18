#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
vector<int> adj[222222];
vector<int> node[222222];
vector<int> scc[222222];
int vis[222222];
int rev_vis[222222];
int state[111111];
int scc_id[222222];

void dfs(int x, stack<int>& st) {
    vis[x] = 1;
    for (int i = 0; i < node[x].size(); i++) {
        if (vis[node[x][i]]) continue;
        dfs(node[x][i], st);
    }
    st.push(x);
}

void rev_dfs(int x, int id) {
    rev_vis[x] = 1;
    scc_id[x] = id;

    for (int i = 0; i < node[x].size(); i++) {
        if (rev_vis[node[x][i]]) continue;
        rev_dfs(node[x][i], id);
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        int f = adj[i][0];
        int s = adj[i][1];

        if (state[i]) {
            node[f].push_back(s);
            node[s].push_back(f);

            node[f + 1].push_back(s + 1);
            node[s + 1].push_back(f + 1);
        } else {
            node[f].push_back(s + 1);
            node[s + 1].push_back(f);

            node[f + 1].push_back(s);
            node[s].push_back(f + 1);
        }
    }

    stack<int> st;

    for (int i = 1; i <= m * 2; i++) {
        if (vis[i]) continue;
        dfs(i, st);
    }

    int id = 1;
    while (st.size()) {
        if (rev_vis[st.top()]) {
            st.pop();
            continue;
        }

        rev_dfs(st.top(), id);
        id++;
        st.pop();
    }

    for (int i = 1; i <= m; i++) {
        if (scc_id[i * 2 - 1] == scc_id[i * 2]) {
            cout << 0 << endl;
            return;
        }
    }

    cout << 1 << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> state[i];
    }

    int k, a;
    for (int i = 1; i <= m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> a;
            adj[a].push_back(2 * i - 1);
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < adj[i].size(); j++) {
    //         cout << adj[i][j] << sp;
    //     }
    //     cout << endl;
    // }
    solve();

    return 0;
}
