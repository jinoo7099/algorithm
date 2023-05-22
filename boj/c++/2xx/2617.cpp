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

vector<int> adj1[102];
vector<int> adj2[102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // a > b
        adj1[a].push_back(b);

        // b < a
        adj2[b].push_back(a);
    }
    int middle = (n - 1) / 2;

    set<int> ans;
    // 자신보다 가벼운거
    for (int i = 1; i <= n; i++) {
        int vis[102] = {};
        int cnt = 0;

        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while (q.size()) {
            cnt++;
            int cur = q.front();
            q.pop();

            for (auto nxt : adj1[cur]) {
                if (vis[nxt]) continue;

                vis[nxt] = 1;
                q.push(nxt);
            }
        }

        if (cnt - 1 > middle) ans.insert(i);
    }

    // 자신보다 무거운거
    for (int i = 1; i <= n; i++) {
        int vis[102] = {};
        int cnt = 0;

        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while (q.size()) {
            cnt++;
            int cur = q.front();
            q.pop();

            for (auto nxt : adj2[cur]) {
                if (vis[nxt]) continue;

                vis[nxt] = 1;
                q.push(nxt);
            }
        }

        if (cnt - 1 > middle) ans.insert(i);
    }

    cout << ans.size() << endl;

    return 0;
}
