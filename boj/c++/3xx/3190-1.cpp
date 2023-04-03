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

int n, k, l;
int len = 1;
int s_x, s_y, s_d;
int board[102][102];

bool move(int t) {
    int nx = s_x + dx[s_d];
    int ny = s_y + dy[s_d];

    if (nx < 1 || nx > n || ny < 1 || ny > n) return false;
    if (board[nx][ny] and len >= t - board[nx][ny]) return false;
    if (board[nx][ny] == -1) {
        len++;
    }

    s_x = nx;
    s_y = ny;
    board[s_x][s_y] = t;

    return true;
}

void changeDir(int t, vector<pair<int, int>> dirs) {
    int l = dirs.size();
    for (int i = 0; i < l; i++) {
        if (t == dirs[i].first) {
            if (dirs[i].second == 'L') {
                s_d = (s_d - 1 + 4) % 4;
            } else if (dirs[i].second == 'D') {
                s_d = (s_d + 1) % 4;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = -1;
    }

    cin >> l;
    vector<pair<int, int>> dirs;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        dirs.push_back({x, c});
    }

    int t = 1;
    s_x = s_y = 1;
    s_d = 1;

    while (1) {
        int res = move(t);
        if (!res) break;
        changeDir(t, dirs);

        t++;
    }

    cout << t << endl;

    return 0;
}
