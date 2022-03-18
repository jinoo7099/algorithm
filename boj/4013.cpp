#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, s, p, res;
vector<int> adj[500005], rev_adj[500005], scc[500005], scc_adj[500005];
int vis[500005];
int rev_vis[500005];
int scc_vis[500005];
int scc_id[500005];
int scc_sum[500005];
int scc_mart[500005];
int val[500005];
int mart[500005];

void dfs(int x, stack<int>& st) {
    vis[x] = 1;
    for (int i = 0; i < adj[x].size(); i++) {
        if (vis[adj[x][i]]) continue;
        dfs(adj[x][i], st);
    }
    st.push(x);
}

void rev_dfs(int x, int id) {
    if (mart[x])
        scc_mart[id] = 1;

    rev_vis[x] = 1;
    scc_id[x] = id;
    scc[id].push_back(x);
    scc_sum[id] += val[x];

    for (int i = 0; i < rev_adj[x].size(); i++) {
        if (rev_vis[rev_adj[x][i]]) {
            // scc 간 간선 만들기
            scc_adj[scc_id[rev_adj[x][i]]].push_back(id);
            continue;
        }
        rev_dfs(rev_adj[x][i], id);
    }
}

void getMax(int x, int sum) {
    if (scc_mart[x])
        res = max(res, sum);
    if (!scc_adj[x].size()) {
        return;
    }

    for (int i = 0; i < scc_adj[x].size(); i++) {
        if (!scc_vis[scc_adj[x][i]]) {
            // cout << x << " " << scc_adj[x][i] << "#" << endl;
            scc_vis[scc_adj[x][i]] = 1;
            getMax(scc_adj[x][i], sum + scc_sum[scc_adj[x][i]]);
            scc_vis[scc_adj[x][i]] = 0;
        }
    }
}

void solve() {
    stack<int> st;

    // get scc stack
    // dfs(s, st);  // start location
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i, st);
    }

    // get scc
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

    // for (int i = 1; i < id; i++) {
    //     cout << "@" << scc_sum[i] << endl;
    //     cout << "#" << scc_id[i] << endl;
    // }

    // get max money
    scc_vis[scc_id[s]] = 1;
    getMax(scc_id[s], scc_sum[scc_id[s]]);

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a;
        val[i] = a;
    }

    cin >> s >> p;
    for (int i = 1; i <= p; i++) {
        cin >> a;
        mart[a] = 1;
    }

    solve();

    return 0;
}
