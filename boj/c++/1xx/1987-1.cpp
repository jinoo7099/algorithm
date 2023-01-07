#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int r, c;
char d[32][32];
int vis[32][32];
int alpha[256];
int ans = 0;

void go(int x, int y, int cur) {
    ans = max(ans, cur);
    if (r == x && c == y) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (vis[nx][ny]) continue;
        if (alpha[d[nx][ny] - 'A']) continue;

        vis[nx][ny] = 1;
        alpha[d[nx][ny] - 'A'] = 1;

        go(nx, ny, cur + 1);

        vis[nx][ny] = 0;
        alpha[d[nx][ny] - 'A'] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> d[i][j];
        }
    }

    vis[0][0] = 1;
    alpha[d[0][0] - 'A'] = 1;

    go(0, 0, 0);

    cout << ans + 1 << endl;

    return 0;
}
