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

int n, m;
int st, en;
vector<pair<int, int>> adj[1002];
vector<int> dist(1002, 1e9);

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, st});
    dist[st] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (cur.X != dist[cur.Y]) continue;
        for (auto nxt : adj[cur.Y]) {
            if (dist[nxt.Y] > nxt.X + dist[cur.Y]) {
                dist[nxt.Y] = nxt.X + dist[cur.Y];
                pq.push({dist[nxt.Y], nxt.Y});
            }
        }
    }

    cout << dist[en] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }
    cin >> st >> en;

    solve();
    return 0;
}
