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

int n, r, q;
vector<int> adj[100002];
int subtreeSize[100002];
int vis[100002];

int countSubtreeNodes(int cur) {
    vis[cur] = 1;

    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        subtreeSize[cur] += countSubtreeNodes(nxt);
    }

    subtreeSize[cur]++;
    return subtreeSize[cur];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    countSubtreeNodes(r);

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cout << subtreeSize[k] << endl;
    }

    return 0;
}
