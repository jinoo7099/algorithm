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

int n, m, k;
int arr[22][22];   // 현재 상어 위치
pii dist[22][22];  // 상어 번호, 냄새
vector<int> shark_cur_dir;
vector<pii> shark_cur_dist;         // x, y
int shark_priority_dir[502][5][5];  // shark num, 방향, 우선순위

void move(int t) {
    for (int i = shark_cur_dist.size() - 1; i >= 0; i--) {
        int shark_num = i;
        int shark_dir = shark_cur_dir[shark_num];

        // 방향 정하기
        int shark_nxt_dir = -1;
        // 상어마다 갖고 있는 방향에서의 우선순위에 따라서 움직임
        for (int d = 0; d < 4; d++) {
            int dd = shark_priority_dir[shark_num][shark_dir][d];
            int nx = shark_cur_dist[shark_num].first + dx[dd];
            int ny = shark_cur_dist[shark_num].second + dy[dd];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny].first != shark_num and dist[nx][ny].second + k <= t) {
                shark_nxt_dir = d;
                break;
            }
        }

        if (shark_nxt_dir == -1) {
            for (int d = 0; d < 4; d++) {
                int dd = shark_priority_dir[shark_num][shark_dir][d];
                int nx = shark_cur_dist[shark_num].first + dx[dd];
                int ny = shark_cur_dist[shark_num].second + dy[dd];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[nx][ny].first == shark_num) {
                    shark_nxt_dir = d;
                    break;
                }
            }
        }

        int nx = shark_cur_dist[shark_num].first + dx[shark_nxt_dir];
        int ny = shark_cur_dist[shark_num].second + dy[shark_nxt_dir];
        // 냄새 뿌리기
        dist[nx][ny] = {shark_num, t};

        // 위치 바꿔주기
        arr[shark_cur_dist[shark_num].first][shark_cur_dist[shark_num].second] = 0;
        shark_cur_dist[shark_num] = {nx, ny};

        // 방향 바꿔주기
        shark_cur_dir[shark_num] = dd;
    }
}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] != 0) {
                dist[i][j] = {shark_cur_dist.size(), 1};
                shark_cur_dist.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        shark_cur_dir.push_back(d);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                int a;
                cin >> a;

                shark_priority_dir[i][j][k] = a - 1;
            }
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout <<
    //     }
    // }

    int t = 1;
    while (t < 1000) {
        move(t);
        // check();
        t++;
    }

    return 0;
}
