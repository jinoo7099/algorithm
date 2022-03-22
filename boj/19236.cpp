#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

struct Fish {
    int row;
    int col;
    int dir;
    bool live;

    Fish() {}

    Fish(int r, int c, int d, bool l) {
        row = r;
        col = c;
        dir = d;
        live = l;
    }
};

int n = 4, res;

void dfs(int dist[4][4], vector<Fish> fishs, int row, int col, int sum) {
    int t_dist[4][4];
    vector<Fish> t_fishs;

    memcpy(t_dist, dist, sizeof(t_dist));

    for (int i = 0; i < fishs.size(); i++) {
        t_fishs.push_back(fishs[i]);
    }
    // 잡아 먹기
    int start_id = t_dist[row][col];
    t_fishs[start_id].live = false;
    sum += start_id;
    int shark_dir = t_fishs[start_id].dir;
    t_dist[row][col] = -1;

    res = max(sum, res);

    // 물고기 이동
    for (int i = 1; i <= 16; i++) {
        Fish fish = t_fishs[i];
        if (!fish.live) continue;

        for (int d = 0; d < 8; d++) {
            int next_dir = (fish.dir + d) % 8;
            int nx = fish.row + dx[next_dir];
            int ny = fish.col + dy[next_dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (t_dist[nx][ny] == -1) continue;

            if (t_dist[nx][ny] == 0) {
                t_dist[nx][ny] = i;
                t_dist[fish.row][fish.col] = 0;
                t_fishs[i] = Fish(nx, ny, next_dir, true);
            } else {
                // 가는거
                int next_fish_id = t_dist[nx][ny];
                t_dist[nx][ny] = i;
                t_fishs[i] = Fish(nx, ny, next_dir, true);

                // 오는거
                t_dist[fish.row][fish.col] = next_fish_id;
                t_fishs[next_fish_id] = Fish(fish.row, fish.col, t_fishs[next_fish_id].dir, true);
            }
            break;
        }
    }

    // 완전 탐색
    for (int i = 1; i <= 3; i++) {
        int nx = row + dx[shark_dir] * i;
        int ny = col + dy[shark_dir] * i;

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (!t_dist[nx][ny]) continue;

        t_fishs[t_dist[nx][ny]].live = false;
        t_dist[row][col] = 0;
        dfs(t_dist, t_fishs, nx, ny, sum);
        t_fishs[t_dist[nx][ny]].live = true;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int dist[4][4];
    vector<Fish> fishs(17, Fish(0, 0, 0, true));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            dist[i][j] = a;
            fishs[a] = Fish(i, j, b - 1, true);
        }
    }

    dfs(dist, fishs, 0, 0, 0);

    cout << res << endl;

    return 0;
}
