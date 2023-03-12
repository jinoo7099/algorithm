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

int n, q;
int N;
int arr[100][100];

void rotate(int size, int st_x, int st_y) {
    int tmp[100][100];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tmp[i + st_x][j + st_y] = arr[st_x + size - 1 - j][st_y + i];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i + st_x][j + st_y] = tmp[i + st_x][j + st_y];
        }
    }
}

void step2() {
    int tmp[100][100];
    memset(tmp, 0, sizeof(tmp));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int adj_ice_cnt = 0;
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if (arr[nx][ny] == 0) continue;
                adj_ice_cnt++;
            }

            if (adj_ice_cnt <= 2) {
                tmp[i][j] = (arr[i][j] - 1) < 0 ? 0 : (arr[i][j] - 1);
            } else {
                tmp[i][j] = arr[i][j];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

void solve(int k) {
    int SIZE = (1 << k);

    // cout << "BEFORE" << endl;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for (int i = 1; i <= N; i += SIZE) {
        for (int j = 1; j <= N; j += SIZE) {
            rotate(SIZE, i, j);
        }
    }
    // cout << "AFTER" << endl;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    step2();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    N = (1 << n);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;

        solve(k);
    }

    int total_ice_cnt = 0;
    int max_ice_cnt = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            total_ice_cnt += arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == 0) continue;

            queue<pii> q;
            int vis[100][100];
            memset(vis, 0, sizeof(vis));

            q.push({i, j});
            vis[i][j] = 1;
            int cnt = 0;

            while (q.size()) {
                cnt++;
                auto cur = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.first + dx[d];
                    int ny = cur.second + dy[d];

                    if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                    if (vis[nx][ny] || arr[nx][ny] == 0) continue;

                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }

            max_ice_cnt = max(max_ice_cnt, cnt);
        }
    }

    cout << total_ice_cnt << endl;
    cout << max_ice_cnt << endl;
    return 0;
}
