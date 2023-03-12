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
int arr[22][22];
int vis[22][22];
vector<tuple<int, int, int, int>> blocks;
int ans;
bool isEnd;

bool cmp(tuple<int, int, int, int>& t1, tuple<int, int, int, int>& t2) {
    if (get<0>(t1) != get<0>(t2)) return get<0>(t1) > get<0>(t2);
    if (get<1>(t1) != get<1>(t2)) return get<1>(t1) > get<1>(t2);
    if (get<2>(t1) != get<2>(t2)) return get<2>(t1) > get<2>(t2);
    return get<3>(t1) > get<3>(t2);
}

void bfs(int x, int y) {
    memset(vis, 0, sizeof(vis));

    queue<pii> q;
    q.push({x, y});
    vis[x][y] = 1;

    int s_block = arr[x][y];
    // int s_block_x, s_block_y;
    // s_block_x = x;
    // s_block_y = y;

    int cnt = 0;
    int rainbow_block_cnt = 0;

    vector<pair<int, int>> t;
    t.push_back({x, y});

    while (q.size()) {
        cnt++;
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (vis[nx][ny] || arr[nx][ny] <= -1) continue;

            if (arr[nx][ny] == s_block || arr[nx][ny] == 0) {
                q.push({nx, ny});
                vis[nx][ny] = 1;

                if (arr[nx][ny] == 0) {
                    rainbow_block_cnt++;
                } else {
                    t.push_back({nx, ny});
                }
            }
        }
    }
    sort(t.begin(), t.end());

    if (t.size() > 0) {
        blocks.push_back({cnt, rainbow_block_cnt, t[0].first, t[0].second});
    }
}

void removeBlock(int x, int y) {
    memset(vis, 0, sizeof(vis));
    queue<pii> q;
    q.push({x, y});
    vis[x][y] = 1;

    int s_block = arr[x][y];
    arr[x][y] = -2;

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (vis[nx][ny] || arr[nx][ny] <= -1) continue;

            if (arr[nx][ny] == s_block || arr[nx][ny] == 0) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
                arr[nx][ny] = -2;
            }
        }
    }
}

void goGravityCol(int col) {
    vector<int> tmp;
    // 20 * 20 * 20 400 8000
    for (int i = 1; i <= n + 1; i++) {
        if (arr[i][col] == -1 || i == n + 1) {
            for (int j = 0; j < tmp.size(); j++) {
                arr[i - 1 - j][col] = tmp[tmp.size() - 1 - j];
            }
            tmp.clear();
        } else if (arr[i][col] >= 0) {
            tmp.push_back(arr[i][col]);
            arr[i][col] = -2;
        }
    }
}

void rotate() {
    int tmp[55][55];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            tmp[i][j] = arr[j][n - i + 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] > 0) {
                bfs(i, j);
            }
        }
    }

    sort(blocks.begin(), blocks.end(), cmp);

    if (get<0>(blocks[0]) < 2 || blocks.size() == 0) {
        isEnd = true;
        return;
    }

    ans += get<0>(blocks[0]) * get<0>(blocks[0]);
    removeBlock(get<2>(blocks[0]), get<3>(blocks[0]));
    for (int i = 1; i <= n; i++) {
        goGravityCol(i);
    }

    rotate();

    for (int i = 1; i <= n; i++) {
        goGravityCol(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    // int k = 5;
    while (1) {
        blocks.clear();
        solve();
        if (isEnd) break;
    }
    cout << ans << endl;

    return 0;
}
