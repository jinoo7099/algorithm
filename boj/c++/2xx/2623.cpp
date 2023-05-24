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

int n, m;
vector<int> adj[1002];
int deg[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        int pre, cur;
        cin >> pre;

        for (int j = 1; j < k; j++) {
            cin >> cur;
            adj[pre].push_back(cur);
            deg[cur]++;

            pre = cur;
        }
    }

    queue<int> q;
    vector<int> ans;

    for (int i = 1; i <= n; i++)
        if (deg[i] == 0) q.push(i);

    while (q.size()) {
        int cur = q.front();
        q.pop();

        ans.push_back(cur);
        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }

    if (ans.size() != n) {
        cout << 0 << endl;
        for (auto x : ans) cout << x << endl;

    } else {
        for (auto x : ans) cout << x << endl;
    }

    return 0;
}
