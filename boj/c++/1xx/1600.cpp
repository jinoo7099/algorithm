#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[] = {-1, 0, 1, 0, -2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1};

int k;
int w, h;
int arr[202][202];
int vis[202][202][52];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 200 * 200 40000
    cin >> k;
    cin >> w >> h;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> arr[i][j];
        }
    }

    // queue<pair<int, pair<int, int>>> q;
    queue<tuple<int, int, int, int>> q;  // k, 횟수, x, y
    q.push({k, 0, 1, 1});
    for (int i = 0; i <= k; i++) {
        vis[1][1][i] = 1;
    }
    while (q.size()) {
        auto [kk, cnt, x, y] = q.front();
        q.pop();

        if (x == h and y == w) {
            cout << cnt << endl;
            return 0;
        }

        for (int i = 0; i < 12; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > h || ny < 1 || ny > w) continue;
            if (vis[nx][ny][kk] || arr[nx][ny] == 1) continue;

            if (i < 4) {
                vis[nx][ny][kk] = 1;
                q.push({kk, cnt + 1, nx, ny});
            } else {
                if (kk > 0 and !vis[nx][ny][kk - 1]) {
                    vis[nx][ny][kk - 1] = 1;
                    q.push({kk - 1, cnt + 1, nx, ny});
                }
            }
        }
    }

    // for (int l = 0; l <= k; l++) {
    //     for (int i = 1; i <= h; i++) {
    //         for (int j = 1; j <= w; j++) {
    //             cout << vis[i][j][l] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    cout << -1 << endl;

    return 0;
}
