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

int n, q;

vector<pair<int, int>> adj[5002];
int vis[5002];
void solve(int k, int v) {
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    int cnt = 0;

    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (int j = 0; j < adj[cur].size(); j++) {
            int nxt = adj[cur][j].first;
            int nxt_cost = adj[cur][j].second;

            if (vis[nxt] || nxt_cost < k) continue;

            q.push(nxt);
            vis[nxt] = 1;
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        adj[x].push_back({y, r});
        adj[y].push_back({x, r});
    }

    for (int i = 0; i < q; i++) {
        int k, x;
        int ans = 0;
        memset(vis, 0, sizeof(vis));

        cin >> k >> x;

        solve(k, x);
    }

    return 0;
}
