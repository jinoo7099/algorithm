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

int n, k;
int vis[100001];
int pre[100001];
int dist[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    queue<int> q;
    q.push(n);
    vis[n] = 0;

    int ans;
    while (q.size()) {
        int cur = q.front();
        q.pop();

        if (cur == k) {
            ans = dist[cur];
            break;
        }

        int go[3] = {cur - 1, cur + 1, 2 * cur};
        for (int i = 0; i < 3; i++) {
            int nx = go[i];
            if (0 <= nx and nx <= 100000 and !vis[nx]) {
                q.push(nx);
                vis[nx] = 1;
                dist[nx] = dist[cur] + 1;
                pre[nx] = cur;
            }
        }
    }

    vector<int> path;
    path.push_back(k);
    for (int i = 0; i < ans; i++) {
        path.push_back(pre[k]);
        k = pre[k];
    }

    cout << ans << endl;
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << ' ';

    return 0;
}
