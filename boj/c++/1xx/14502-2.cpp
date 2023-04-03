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
int arr[12][12];
int vis[12][12];
int ans;

void bfs() {
    int tmp[12][12];
    queue<pii> q;
    bool ch[12][12] = {
        false,
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tmp[i][j] = arr[i][j];
            if (tmp[i][j] == 2) {
                q.push({i, j});
                ch[i][j] = 1;
            }
        }
    }

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (ch[nx][ny] || tmp[nx][ny] != 0) continue;

            ch[nx][ny] = 1;
            tmp[nx][ny] = 2;
            q.push({nx, ny});
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (tmp[i][j] == 0) cnt++;
        }
    }
    ans = max(ans, cnt);
}

void make_wall(int cur) {
    if (cur == 3) {
        bfs();
        return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] || arr[i][j] != 0) continue;

            vis[i][j] = 1;
            arr[i][j] = 1;
            make_wall(cur + 1);
            arr[i][j] = 0;
            vis[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    make_wall(0);

    cout << ans << endl;

    return 0;
}
