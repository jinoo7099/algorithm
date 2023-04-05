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
int s_x, s_y, s_size = 2;
int catch_cnt;
int vis[22][22];

bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
    auto [d1, x1, y1] = t1;
    auto [d2, x2, y2] = t2;
    if (d1 != d2) return d1 < d2;
    if (x1 != x2) return x1 < x2;
    return y1 < y2;
}

vector<tuple<int, int, int>> findCatchedFishs() {
    memset(vis, 0, sizeof(vis));
    vector<tuple<int, int, int>> ret;
    queue<pair<int, int>> q;
    q.push({s_x, s_y});
    vis[s_x][s_y] = 1;

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (vis[nx][ny]) continue;
            if (arr[nx][ny] > s_size) continue;

            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});

            if (arr[nx][ny] > 0 and arr[nx][ny] < s_size) {
                ret.push_back({vis[cur.first][cur.second], nx, ny});
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 9) {
                s_x = i;
                s_y = j;
            }
        }
    }
    int t = 0;
    while (1) {
        vector<tuple<int, int, int>> fishs = findCatchedFishs();  // 거리, x, y

        if (fishs.size() == 0) break;

        sort(fishs.begin(), fishs.end(), cmp);
        auto [d, x, y] = fishs[0];
        arr[s_x][s_y] = 0;
        s_x = x;
        s_y = y;
        arr[s_x][s_y] = 9;

        catch_cnt++;
        if (catch_cnt == s_size) {
            s_size++;
            catch_cnt = 0;
        }

        t += d;
    }

    cout << t << endl;

    return 0;
}
