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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, k;
    cin >> v >> e;
    cin >> k;

    vector<vector<pair<int, int>>> adj(v + 1);
    vector<int> dist(v + 1, 1e9);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[k] = 0;
    pq.push({dist[k], k});

    while (pq.size()) {
        auto cur = pq.top();
        pq.pop();

        if (dist[cur.Y] != cur.X) continue;
        for (auto nxt : adj[cur.Y]) {
            if (dist[nxt.Y] > dist[cur.Y] + nxt.X) {
                dist[nxt.Y] = dist[cur.Y] + nxt.X;
                pq.push({dist[nxt.Y], nxt.Y});
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == 1e9)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }

    return 0;
}
