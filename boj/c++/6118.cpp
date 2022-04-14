#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
vector<int> adj[20002];
int vis[20002];
vector<int> res[20002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    fill(vis, vis + 20001, -1);
    vis[1] = 0;
    int maxx = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            if (vis[next] != -1) continue;
            q.push(next);
            vis[next] = vis[cur] + 1;
            maxx = max(maxx, vis[next]);
            res[vis[next]].push_back(next);
        }
    }

    sort(res[maxx].begin(), res[maxx].end());
    cout << res[maxx][0] << ' ' << maxx << ' ' << res[maxx].size() << endl;

    return 0;
}
