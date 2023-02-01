#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[6] = {-1, 0, 1, 0, 0, 0};
const int dy[6] = {0, 1, 0, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, -1, 1};

int d[10][10][10];
int vis[10][10][10];
int tmp[10][10][10];
int ans = 1e9;

void bfs() {
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         for (int k = 0; k < 5; k++) {
    //             cout << tmp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // cout << " ####" << endl;
    memset(vis, 0, sizeof(vis));

    queue<pair<int, pair<int, int>>> q;
    if (tmp[0][0][0] == 0) return;

    q.push({0, {0, 0}});
    vis[0][0][0] = 1;

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second.first + dy[i];
            int nz = cur.second.second + dz[i];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
            if (vis[nx][ny][nz] || tmp[nx][ny][nz] == 0) continue;

            q.push({nx, {ny, nz}});
            vis[nx][ny][nz] = vis[cur.first][cur.second.first][cur.second.second] + 1;
        }
    }

    if (vis[4][4][4]) {
        ans = min(ans, vis[4][4][4]);
    }
}

void rotate(int p) {
    int t[10][10];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            t[i][j] = tmp[p][i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tmp[p][i][j] = t[5 - 1 - j][i];
        }
    }
}

void solve() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int ii = 0; ii < 4; ii++) {
                    for (int jj = 0; jj < 4; jj++) {
                        bfs();
                        rotate(4);
                    }
                    rotate(3);
                }
                rotate(2);
            }
            rotate(1);
        }
        rotate(0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 120 * 5 *5 *5 * 5* 5
    // 120 * 625 * 5
    // 600 * 625 * 125

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> d[i][j][k];
            }
        }
    }

    vector<int> v{1, 2, 3, 4, 5};

    do {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    tmp[i][j][k] = d[v[i] - 1][j][k];
                }
            }
        }
        // bfs();
        solve();

    } while (next_permutation(v.begin(), v.end()));

    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans - 1 << endl;
    }
    return 0;
}
