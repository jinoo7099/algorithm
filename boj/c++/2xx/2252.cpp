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

vector<int> adj[50002];
int deg[50002];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        deg[v]++;
    }

    queue<int> q;
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }

    while (q.size()) {
        int cur = q.front();
        q.pop();

        ans.push_back(cur);
        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }

    for (auto s : ans) {
        cout << s << ' ';
    }

    return 0;
}
