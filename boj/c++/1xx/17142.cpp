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

int arr[52][52];
int vis[52][52];
vector<pair<int, int>> v;
vector<int> t;

int n, m;
int empty_place;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                v.push_back({i, j});
            } else if (arr[i][j] == 0) {
                empty_place++;
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (v.size() - m <= i) {
            t.push_back(1);
        } else {
            t.push_back(0);
        }
    }

    int ans = 1e9;

    do {
        memset(vis, -1, sizeof(vis));
        queue<pii> q;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == 1) {
                q.push(v[i]);
                vis[v[i].fi][v[i].se] = 0;
            }
        }

        int i_place = 0;
        int total_time = 0;
        while (q.size()) {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur.fi + dx[i];
                int ny = cur.se + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (vis[nx][ny] != -1 || arr[nx][ny] == 1) continue;

                vis[nx][ny] = vis[cur.fi][cur.se] + 1;
                if (arr[nx][ny] == 0) {
                    i_place++;
                    total_time = vis[nx][ny];
                }
                q.push({nx, ny});
            }
        }
        if (i_place == empty_place) {
            ans = min(ans, total_time);
        }

    } while (next_permutation(t.begin(), t.end()));

    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
