#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int f_dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int f_dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

const int s_dx[] = {0, -1, 0, 1, 0};
const int s_dy[] = {0, 0, -1, 0, 1};
int n = 4, m, s;
int s_x, s_y;

vector<int> fishs[5][5];
vector<int> copy_fishs[5][5];
int smell[5][5];
int vis[5][5];
int t = 1;
int max_removed_fish;
string remove_path;

void copyFish(vector<int> a[][5], vector<int> b[][5]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[i][j] = a[i][j];
        }
    }
}

void moveFishs() {
    vector<int> tmp[5][5];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int f = 0; f < fishs[i][j].size(); f++) {
                int fish_d = fishs[i][j][f];
                int nx, ny, nxt_d;
                bool can_move = false;
                for (int d = 0; d < 8; d++) {
                    nxt_d = (fish_d - d + 8) % 8;
                    nx = i + f_dx[nxt_d];
                    ny = j + f_dy[nxt_d];

                    if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                    if (s_x == nx and s_y == ny) continue;
                    if (smell[nx][ny] != 0 and t - smell[nx][ny] <= 2) continue;

                    can_move = true;
                    break;
                }
                if (can_move) {
                    tmp[nx][ny].push_back(nxt_d);
                } else {
                    tmp[i][j].push_back(fish_d);
                }
            }
        }
    }

    copyFish(tmp, fishs);
}

int simulateShark(string s) {
    bool vis[5][5] = {
        false,
    };
    int x = s_x, y = s_y;
    int ret = 0;

    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - '0';
        x += s_dx[d];
        y += s_dy[d];

        if (x < 1 || x > n || y < 1 || y > n) return -1;

        if (!vis[x][y]) {
            ret += fishs[x][y].size();
            vis[x][y] = 1;
        }
    }

    return ret;
}

void findPath(int cur, int x, int y, string s) {
    if (cur == 3) {
        int removed_fish_num = simulateShark(s);
        if (max_removed_fish < removed_fish_num) {
            max_removed_fish = removed_fish_num;
            remove_path = s;
        }
        return;
    }

    for (int i = 1; i <= 4; i++) {
        int nx = x + s_dx[i];
        int ny = y + s_dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

        vis[nx][ny] = 1;
        findPath(cur + 1, nx, ny, s + to_string(i));
        vis[nx][ny] = 0;
    }
}

void removeFish() {
    string s = remove_path;

    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - '0';
        s_x += s_dx[d];
        s_y += s_dy[d];

        if (fishs[s_x][s_y].size()) {
            smell[s_x][s_y] = t;
            fishs[s_x][s_y].clear();
        }
    }
}

void pasteFish() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < copy_fishs[i][j].size(); k++)
                fishs[i][j].push_back(copy_fishs[i][j][k]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> s;

    for (int i = 0; i < m; i++) {
        int fx, fy, d;
        cin >> fx >> fy >> d;
        fishs[fx][fy].push_back(d - 1);
    }

    cin >> s_x >> s_y;

    while (s--) {
        max_removed_fish = -1;
        copyFish(fishs, copy_fishs);
        moveFishs();

        findPath(0, s_x, s_y, "");
        removeFish();

        pasteFish();
        t++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += fishs[i][j].size();
        }
    }
    cout << ans << endl;

    return 0;
}
