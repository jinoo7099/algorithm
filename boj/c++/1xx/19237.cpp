#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Shark {
    int x;
    int y;
    int d;
    bool live;

    Shark(int x, int y, int d, int l) {
        this->x = x;
        this->y = y;
        this->d = d;
        this->live = l;
    }
};

int n, m, k;
int cnt;

pair<int, int> arr[30][30];
vector<Shark> sharks(402, Shark(0, 0, 0, false));
int dir[402][4][4];

void solve() {
    cnt = 0;
    while (cnt < 3) {
        cnt++;
        int live_shark = 0;
        cout << cnt << "#####" << endl;

        pair<int, int> dist[30][30];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << '(' << arr[i][j].first << ' ' << arr[i][j].second << ") ";
            }
            cout << endl;
        }
        cout << endl;

        memcpy(dist, arr, sizeof(dist));

        for (int i = m; i >= 1; i--) {
            Shark shark = sharks[i];
            if (!shark.live) continue;

            live_shark++;
            bool check = false;

            for (int j = 0; j < 4; j++) {
                int dd = dir[i][shark.d][j];

                int nx = shark.x + dx[dd];
                int ny = shark.y + dy[dd];

                if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                if (dist[nx][ny].second >= cnt - k) continue;

                if (arr[nx][ny].first > i && arr[nx][ny].second == cnt) {
                    sharks[arr[nx][ny].first].live = false;
                }
                check = true;
                arr[nx][ny] = {i, cnt};
                sharks[i] = Shark(nx, ny, dd, true);
                break;
            }

            // 냄새 없는 곳이 없을때
            if (!check) {
                for (int j = 0; j < 4; j++) {
                    int dd = dir[i][shark.d][j];

                    int nx = shark.x + dx[dd];
                    int ny = shark.y + dy[dd];

                    if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

                    // 자신의 냄새인 곳
                    if (dist[nx][ny].first == i) {
                        cout << i << ' ' << nx << " " << ny << "##" << dd << endl;
                        for (int jj = 0; jj < 4; jj++) {
                            int ddd = dir[i][dd][jj];

                            int nxx = shark.x + dx[ddd];
                            int nyy = shark.y + dy[ddd];

                            if (nxx < 1 || nxx > n || nyy < 1 || nyy > n) continue;
                            if (dist[nxx][nyy].first == i) {
                                arr[nxx][nyy] = {i, cnt};
                                sharks[i] = Shark(nxx, nyy, ddd, true);
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }

        if (live_shark == 1) break;
    }

    if (cnt >= 1000)
        cout << -1 << endl;
    else
        cout << cnt - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a) {
                sharks[a] = Shark(i, j, -1, true);
                arr[i][j] = {a, cnt};
            } else {
                arr[i][j] = {a, -1001};
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int dir;
        cin >> dir;
        sharks[i + 1].d = dir - 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 4; j++) {
            for (int l = 0; l < 4; l++) {
                int s;
                cin >> s;
                dir[i][j][l] = s - 1;
            }
        }
    }

    solve();

    return 0;
}
