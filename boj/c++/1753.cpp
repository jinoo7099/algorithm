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

int V, E, K;
vector<pair<int, int>> adj[20002];
vector<int> d(20002, 1e9);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> K;

    for (int i = 1; i <= E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
    }

    priority_queue<pii, vector<pii>, greater<>> pq;

    d[K] = 0;
    pq.push({d[K], K});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (d[cur.Y] != cur.X) continue;
        for (auto next : adj[cur.Y]) {
            if (d[next.Y] <= d[cur.Y] + next.X) continue;

            d[next.Y] = d[cur.Y] + next.X;
            pq.push({d[next.Y], next.Y});
        }
    }

    for (int i = 1; i <= V; i++) {
        if (d[i] == 1e9)
            cout << "INF" << endl;
        else
            cout << d[i] << endl;
    }
    return 0;
}
