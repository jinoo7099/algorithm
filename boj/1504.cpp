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

int n, e;
int aa, bb;
vector<pair<int, int>> adj[1000];
int d[1000];

void solve(int st) {
    fill(d, d + 1000, 987654321);

    d[st] = 0;

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({d[st], st});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;

            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> aa >> bb;
    int first[1000], se[1000], th[1000];
    solve(1);

    for (int i = 1; i <= n; i++) {
        first[i] = d[i];
    }

    solve(aa);
    for (int i = 1; i <= n; i++) {
        se[i] = d[i];
    }

    solve(bb);
    for (int i = 1; i <= n; i++) {
        th[i] = d[i];
    }

    int ans = min(first[aa] + se[bb] + th[n], first[bb] + th[aa] + se[n]);
    if (ans > 987654321 || ans < 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
