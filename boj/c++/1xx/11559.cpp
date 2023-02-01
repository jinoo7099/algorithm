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

int r = 12, c = 6;
char d[22][22];
int vis[22][22];
int ans;
bool is_puyo;

void bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    vis[x][y] = 1;
    char color = d[x][y];
    set<pii> s;

    while (q.size()) {
        auto cur = q.front();
        q.pop();
        s.insert({cur.first, cur.second});
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (vis[nx][ny] || d[nx][ny] != color) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }

    if (s.size() >= 4) {
        is_puyo = true;
        for (auto el : s) {
            d[el.first][el.second] = '.';
        }
    }
}

void down() {
    for (int j = 0; j < c; j++) {
        vector<char> v;
        for (int i = r - 1; i >= 0; i--) {
            if (d[i][j] != '.') {
                v.push_back(d[i][j]);
                d[i][j] = '.';
            }
        }

        for (int i = 0; i < v.size(); i++) {
            d[r - 1 - i][j] = v[i];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> d[i][j];
        }
    }

    while (1) {
        is_puyo = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // bfs
                if (d[i][j] != '.' && !vis[i][j]) {
                    bfs(i, j);
                }
            }
        }
        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         cout << d[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if (!is_puyo) break;
        down();
        ans += 1;
    }

    cout << ans << endl;

    return 0;
}
