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
string arr[22];
int vis[22][22];
int alpha[26];
int ans = -1;

void solve(int x, int y, int cnt) {
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (vis[nx][ny] || alpha[arr[nx][ny] - 'A']) continue;

        vis[nx][ny] = 1;
        alpha[arr[nx][ny] - 'A'] = 1;

        solve(nx, ny, cnt + 1);

        alpha[arr[nx][ny] - 'A'] = 0;
        vis[nx][ny] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> arr[i];
    }

    vis[0][0] = 1;
    alpha[arr[0][0] - 'A'] = 1;

    solve(0, 0, 1);

    cout << ans << endl;
    return 0;
}
