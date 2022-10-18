#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, k;
int arr[222][222];
int vis[222][222];

vector<pair<int, int>> v[1111];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    int s, x, y;
    cin >> s >> x >> y;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j]) {
                v[arr[i][j]].push_back({i, j});
                vis[i][j] = 1;
            }
        }
    }
    queue<pair<int, int>> q;

    for (int i = 1; i <= k; i++) {
        for (auto a : v[i]) {
            q.push({a.first, a.second});
        }
    }

    while (s--) {
        int sz = q.size();
        while (sz--) {
            pair<int, int> cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                if (vis[nx][ny] || arr[nx][ny]) continue;

                q.push({nx, ny});
                vis[nx][ny] = 1;
                arr[nx][ny] = arr[cur.first][cur.second];
            }
        }
    }

    cout << arr[x][y] << endl;

    return 0;
}
