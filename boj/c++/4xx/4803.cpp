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

int ans;
int vis[502];
bool isTree = true;
vector<int> adj[502];

void dfs(int x, int par) {
    for (auto nxt : adj[x]) {
        if (nxt == par)
            continue;
        if (vis[nxt]) {
            isTree = false;
            continue;
        }

        vis[nxt] = 1;
        dfs(nxt, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0;
    while (1) {
        t++;
        int n, m;
        ans = 0;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        // init
        fill(vis, vis + 501, 0);
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;

            vis[i] = true;
            isTree = true;
            dfs(i, -1);

            ans += isTree;
        }

        cout << "Case " << t << ": ";
        if (ans == 0) {
            cout << "No trees." << endl;
        } else if (ans == 1) {
            cout << "There is one tree." << endl;
        } else {
            cout << "A forest of " << ans << " trees." << endl;
        }
    }
    return 0;
}
