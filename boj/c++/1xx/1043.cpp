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

vector<int> pt[52];   // party
vector<int> adj[52];  // 간선
int tr[52];
int n, m, t;

void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (tr[i]) q.push(i);
    }

    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (auto nxt : adj[cur]) {
            if (tr[nxt]) continue;

            tr[nxt] = 1;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> t;

    while (t--) {
        int x;
        cin >> x;
        tr[x] = 1;
    }

    for (int i = 0; i < m; i++) {
        int no;
        cin >> no;

        int prev, nxt;
        cin >> prev;
        pt[i].push_back(prev);

        while (--no) {
            cin >> nxt;
            pt[i].push_back(nxt);

            adj[nxt].push_back(prev);
            adj[prev].push_back(nxt);

            swap(prev, nxt);
        }
    }

    bfs();

    int ans = 0;

    for (int i = 0; i < m; i++) {
        bool known = 0;
        for (int p : pt[i])
            if (tr[p]) known = 1;
        if (!known) ans++;
    }
    cout << ans << endl;

    return 0;
}
