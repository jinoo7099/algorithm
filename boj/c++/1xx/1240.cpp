#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
vector<pair<int, int>> adj[1002];
int dist[1002];

void dfs(int cur) {
    for (auto nxt : adj[cur]) {
        if (dist[nxt.second] != -1) continue;

        dist[nxt.second] = dist[cur] + nxt.first;
        dfs(nxt.second);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int u, v, dist;
        cin >> u >> v >> dist;
        adj[u].push_back({dist, v});
        adj[v].push_back({dist, u});
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        ans = 0;
        fill(dist, dist + 1001, -1);

        int st, en;
        cin >> st >> en;

        dist[st] = 0;
        dfs(st);

        cout << dist[en] << endl;
    }

    return 0;
}
