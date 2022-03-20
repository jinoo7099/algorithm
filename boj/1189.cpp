#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int r, c, k;
char arr[10][10];
int vis[10][10];
int res[50];

void solve(int row, int col, int cur) {
    if (row == 0 && col == c - 1) {
        res[cur]++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = row + dx[i];
        int ny = col + dy[i];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (arr[nx][ny] == 'T') continue;
        if (vis[nx][ny]) continue;

        vis[nx][ny] = 1;
        solve(nx, ny, cur + 1);
        vis[nx][ny] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> k;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    vis[r - 1][0] = 1;
    solve(r - 1, 0, 0);
    cout << res[k - 1] << endl;
    return 0;
}
