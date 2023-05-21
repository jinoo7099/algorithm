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

vector<int> adj[20002];
int vis[20002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    while (k--) {
        int v, e;
        cin >> v >> e;

        // init
        fill(vis, vis + 20001, 0);
        for (int i = 0; i <= v; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int res = 0;

        for (int st = 1; st <= v; st++) {
            if (vis[st]) continue;
            if (res > 2) break;

            res++;
            queue<int> q;
            q.push(st);
            vis[st] = 1;

            while (q.size()) {
                int cur = q.front();
                q.pop();

                for (auto nxt : adj[cur]) {
                    if (vis[nxt]) continue;

                    vis[nxt] = 1;
                    q.push(nxt);
                }
            }
        }

        cout << res << endl;

        if (res == 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
