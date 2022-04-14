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

int n, m;
vector<vector<int>> arr;
vector<pair<int, pair<int, int>>> cc;
// vector<vector<int>> vis[10][10];
int ans = 1e9;

vector<vector<int>> changeDist(vector<vector<int>> dist, int d, int x, int y) {
    for (int i = 0; i < 10; i++) {
        int nx = x + dx[d] * i;
        int ny = y + dy[d] * i;

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (dist[nx][ny] == 6) break;
        if (dist[nx][ny]) continue;
        dist[nx][ny] = 1;
    }
    return dist;
}

void solve(int cur, vector<vector<int>> arr) {
    if (cur == cc.size()) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!arr[i][j]) cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }

    auto cctv = cc[cur];
    int num = cctv.first;
    int x = cctv.second.first;
    int y = cctv.second.second;

    if (num == 1) {
        for (int d = 0; d < 4; d++) {
            vector<vector<int>> dist = changeDist(arr, d, x, y);
            solve(cur + 1, dist);
        }
    } else if (num == 2) {
        for (int d = 0; d < 2; d++) {
            vector<vector<int>> dist = changeDist(arr, d, x, y);
            dist = changeDist(dist, (d + 2) % 4, x, y);
            solve(cur + 1, dist);
        }
    } else if (num == 3) {
        for (int d = 0; d < 4; d++) {
            vector<vector<int>> dist = changeDist(arr, d, x, y);
            dist = changeDist(dist, (d + 1) % 4, x, y);
            solve(cur + 1, dist);
        }
    } else if (num == 4) {
        for (int d = 0; d < 4; d++) {
            vector<vector<int>> dist = changeDist(arr, d, x, y);
            dist = changeDist(dist, (d + 1) % 4, x, y);
            dist = changeDist(dist, (d + 2) % 4, x, y);
            solve(cur + 1, dist);
        }
    } else if (num == 5) {
        vector<vector<int>> dist = changeDist(arr, 0, x, y);
        for (int d = 1; d < 4; d++) {
            dist = changeDist(dist, d, x, y);
        }
        solve(cur + 1, dist);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > 0 && arr[i][j] != 6) {
                int num = arr[i][j];
                cc.push_back({num, {i, j}});
            }
        }
    }

    solve(0, arr);

    cout << ans << endl;
    return 0;
}
