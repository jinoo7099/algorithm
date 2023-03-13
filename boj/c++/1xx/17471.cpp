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

int n;
int arr[12];
vector<int> adj[12];
int vis[12];
int ans = 1e9;

void solve() {
    for (int i = 0; i < (1 << n); i++) {
        memset(vis, 0, sizeof(vis));

        vector<int> v;
        v.push_back(0);

        int k = i;
        while (k) {
            v.push_back(k % 2);
            k /= 2;
        }

        for (int j = v.size(); j < n + 1; j++) {
            v.push_back(0);
        }

        vector<int> res;
        for (int j = 1; j <= n; j++) {
            if (vis[j]) continue;
            queue<int> q;
            q.push(j);
            vis[j] = 1;
            int area = v[j];
            int sum = 0;

            while (q.size()) {
                auto cur = q.front();
                q.pop();
                sum += arr[cur];

                for (int s = 0; s < adj[cur].size(); s++) {
                    if (vis[adj[cur][s]] || area != v[adj[cur][s]]) continue;

                    vis[adj[cur][s]] = 1;
                    q.push(adj[cur][s]);
                }
            }
            res.push_back(sum);
        }

        if (res.size() == 2) {
            ans = min(ans, abs(res[0] - res[1]));
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            adj[i].push_back(a);
        }
    }
    solve();
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
