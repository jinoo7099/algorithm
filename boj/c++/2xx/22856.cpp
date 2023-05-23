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
int vis[100002];
int lc[100002];
int rc[100002];
int p[100002];
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lc[a] = b;
        rc[a] = c;
        p[b] = a;
        p[c] = a;
    }

    int endpoint = 1;
    while (rc[endpoint] != -1)
        endpoint = rc[endpoint];

    int cur = 1, cnt = 0;
    while (1) {
        vis[cur] = 1;
        cnt++;

        if (lc[cur] != -1 and !vis[lc[cur]]) {
            cur = lc[cur];
        } else if (rc[cur] != -1 and !vis[rc[cur]]) {
            cur = rc[cur];
        } else {
            if (endpoint == cur) {
                break;
            } else {
                cur = p[cur];
            }
        }
    }

    cout << cnt - 1 << endl;

    return 0;
}
