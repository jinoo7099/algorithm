#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, res;
int arr[52][52];
int vis[52][52];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    // 0 북 1 동 2 남 3 서
    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    while (1) {
        if (arr[r][c] == 0) {
            arr[r][c] = 2;
            res++;
        }

        bool checkAll = true;
        int dd;

        for (int i = 1; i <= 4; i++) {
            dd = (d + 3 * i) % 4;

            int nx = r + dx[dd];
            int ny = c + dy[dd];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (arr[nx][ny]) continue;

            checkAll = false;
            r = nx;
            c = ny;
            d = dd;
            break;
        }

        if (checkAll) {
            int back = (dd + 2) % 4;
            int bx = r + dx[back];
            int by = c + dy[back];
            if (arr[bx][by] != 1) {
                r = bx;
                c = by;
            } else {
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}
