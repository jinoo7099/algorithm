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

int n, m;
int r, c, d;
int arr[52][52];
int vis[52][52];
int ans;
void solve() {
    while (1) {
        if (arr[r][c] == 0) {
            arr[r][c] = 2;
            ans++;
        }

        bool can_clean = false;
        int nx, ny, nxt_d;
        for (int i = 0; i < 4; i++) {
            nxt_d = (d - i + 4 - 1) % 4;
            nx = r + dx[nxt_d];
            ny = c + dy[nxt_d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (arr[nx][ny] != 0) continue;
            can_clean = true;
            break;
        }
        if (!can_clean) {
            nx = r + dx[(d + 2) % 4];
            ny = c + dy[(d + 2) % 4];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
            if (arr[nx][ny] == 1) break;

            r = nx;
            c = ny;
        } else {
            if (arr[nx][ny] == 0) {
                r = nx;
                c = ny;
                d = nxt_d;
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    solve();

    cout << ans << endl;

    return 0;
}
