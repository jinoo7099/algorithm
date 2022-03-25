#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, x;
vector<pair<int, int>> adj[11111];
int d[11111];
vector<vector<int>> res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    int ans = -1;

    for (int i = 1; i <= n; i++) {
        fill(d, d + 11111, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        d[i] = 0;
        pq.push({d[i], i});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            if (d[cur.Y] != cur.X) continue;
            for (auto nxt : adj[cur.Y]) {
                if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;

                d[nxt.Y] = d[cur.Y] + nxt.X;
                pq.push({d[nxt.Y], nxt.Y});
            }
        }

        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(d[i]);
        }
        res.push_back(v);
    }

    for (int i = 0; i < res.size(); i++) {
        ans = max(ans, res[i][x - 1] + res[x - 1][i]);
    }
    cout << ans << endl;

    return 0;
}
