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

vector<int> adj[100001];
int vis[100001];
int cycle;

void dfs(int cur, int par) {
    vis[cur] = 1;

    for (auto nxt : adj[cur]) {
        if (nxt == par) continue;
        if (vis[nxt]) {
            cycle++;
            continue;
        }

        vis[nxt] = 1;
        dfs(nxt, cur);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    // 연결 요소 - 1

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int treeCnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        dfs(i, -1);
        treeCnt++;
    }
    cout << cycle << endl;
    cout << treeCnt - 1 + cycle;

    return 0;
}
