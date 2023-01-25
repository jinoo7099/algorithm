#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[6] = {-2, -2, 0, 0, 2, 2};
const int dy[6] = {-1, 1, -2, 2, -1, 1};

int n;
int vis[202][202];
int r1, c1, r2, c2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    queue<pair<int, int>> q;
    q.push({r1, c1});
    vis[r1][c1] = 1;

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == r2 && cur.second == c2) {
            cout << vis[cur.first][cur.second] - 1 << endl;
            return 0;
        }

        for (int i = 0; i < 6; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    cout << -1 << endl;

    return 0;
}
