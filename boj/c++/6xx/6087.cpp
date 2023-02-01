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

char d[102][102];
int vis[102][102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> m >> n;

    queue<pair<pair<int, int>, pair<int, int>>> q;
    // 좌표, 방향, 거울 개수

    int st_r, st_c;
    int end_r, end_c;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];

            if (d[i][j] == 'C') {
                if (!flag) {
                    st_r = i;
                    st_c = j;
                    flag = true;
                } else {
                    end_r = i;
                    end_c = j;
                }
            }
            vis[i][j] = 1e9;
        }
    }

    vis[st_r][st_c] = 0;

    for (int i = 0; i < 4; i++) {
        q.push({{st_r, st_c}, {i, 0}});
    }

    while (q.size()) {
        auto cur = q.front().first;
        auto dir = q.front().second.first;
        auto cnt = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (d[nx][ny] == '*') continue;

            int next_cnt = (i == dir) ? cnt : cnt + 1;

            // 방향이 바꼈을때
            if (vis[nx][ny] >= next_cnt) {
                q.push({{nx, ny}, {i, next_cnt}});
                vis[nx][ny] = next_cnt;
            }
        }
    }

    cout << vis[end_r][end_c] << endl;
    return 0;
}
