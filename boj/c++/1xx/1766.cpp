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
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) pq.push(i);
    }
    vector<int> ans;
    while (pq.size()) {
        int cur = pq.top();
        pq.pop();
        ans.push_back(cur);

        for (auto nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) pq.push(nxt);
        }
    }

    for (auto x : ans) cout << x << ' ';

    return 0;
}
