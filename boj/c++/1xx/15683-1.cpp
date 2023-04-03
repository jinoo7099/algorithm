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
int arr[12][12];
vector<pair<int, pair<int, int>>> cctv;
int ans = 1e9;

void checkCctv(int tmp[][12], int x, int y, int dir) {
    while (1) {
        x += dx[dir];
        y += dy[dir];

        if (x < 1 || x > n || y < 1 || y > m || tmp[x][y] == 6) break;

        tmp[x][y] = -1;
    }
}

void solve(int k) {
    int tmp[12][12];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            tmp[i][j] = arr[i][j];
    vector<int> dirs;
    for (int i = 0; i < cctv.size(); i++) {
        dirs.push_back(k % 4);
        k /= 4;
    }

    for (int i = 0; i < cctv.size(); i++) {
        int dir = dirs[i];

        int cctv_num = cctv[i].first;
        auto [x, y] = cctv[i].second;

        if (cctv_num == 1) {
            checkCctv(tmp, x, y, dir);
        } else if (cctv_num == 2) {
            checkCctv(tmp, x, y, dir);
            checkCctv(tmp, x, y, (dir + 2) % 4);
        } else if (cctv_num == 3) {
            checkCctv(tmp, x, y, dir);
            checkCctv(tmp, x, y, (dir + 1) % 4);
        } else if (cctv_num == 4) {
            checkCctv(tmp, x, y, dir);
            checkCctv(tmp, x, y, (dir + 1) % 4);
            checkCctv(tmp, x, y, (dir + 2) % 4);
        } else if (cctv_num == 5) {
            checkCctv(tmp, x, y, dir);
            checkCctv(tmp, x, y, (dir + 1) % 4);
            checkCctv(tmp, x, y, (dir + 2) % 4);
            checkCctv(tmp, x, y, (dir + 3) % 4);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (tmp[i][j] == 0) {
                cnt++;
            }
        }
    }
    ans = min(ans, cnt);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > 0 and arr[i][j] < 6) {
                cctv.push_back({arr[i][j], {i, j}});
            }
        }
    }
    int size = cctv.size();

    for (int i = 0; i < (1 << size * 2); i++) {
        solve(i);
    }

    cout << ans << endl;

    return 0;
}
