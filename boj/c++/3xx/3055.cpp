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
char d[52][52];
int vis1[52][52];
int vis2[52][52];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pii> q1;
    queue<pii> q2;
    set<pair<int, int>> s;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> d[i][j];

            if (d[i][j] == '*') {
                q1.push({i, j});
                vis1[i][j] = 1;
            } else if (d[i][j] == 'S') {
                q2.push({i, j});
                vis2[i][j] = 1;
            } else if (d[i][j] == 'D') {
                s.insert({i, j});
            }
        }
    }

    while (q1.size()) {
        auto cur = q1.front();
        q1.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (vis1[nx][ny] || d[nx][ny] != '.') continue;

            q1.push({nx, ny});
            vis1[nx][ny] = vis1[cur.first][cur.second] + 1;
        }
    }

    while (q2.size()) {
        auto cur = q2.front();
        q2.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (vis2[nx][ny]) continue;
            if (vis2[cur.first][cur.second] + 1 < vis1[nx][ny] || vis1[nx][ny] == 0) {
                if (d[nx][ny] == '.') {
                    q2.push({nx, ny});
                    vis2[nx][ny] = vis2[cur.first][cur.second] + 1;
                } else if (d[nx][ny] == 'D') {
                    cout << vis2[cur.first][cur.second] << endl;
                    return 0;
                }
            }
        }
    }

    cout << "KAKTUS" << endl;
    return 0;
}
