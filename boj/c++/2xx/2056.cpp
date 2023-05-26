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

vector<int> adj[10002];
int deg[10002];
int times[10002];
int res[10002];
int a, root;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int t, c;
        cin >> t >> c;

        times[i] = t;

        while (c--) {
            cin >> a;
            adj[a].push_back(i);
            deg[i]++;
        }
    }

    int ans = 0;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
        res[i] = times[i];
    }

    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            res[nxt] = max(res[nxt], res[cur] + times[nxt]);
            if (deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        ans = max(ans, res[i]);

    cout << ans << endl;

    return 0;
}
