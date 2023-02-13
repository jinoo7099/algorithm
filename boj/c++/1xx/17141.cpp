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

int arr[52][52];
int vis[52][52];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int ans = 1e9;
    int total_place = 0;
    vector<pii> virus;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                virus.push_back({i, j});
            } else if (arr[i][j] == 0) {
                total_place++;
            }
        }
    }

    vector<int> v;

    for (int i = 0; i < virus.size(); i++) {
        if (i >= virus.size() - m) {
            v.push_back(1);
        } else {
            v.push_back(0);
        }
    }

    do {
        memset(vis, -1, sizeof(vis));
        queue<pii> q;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 1) {
                q.push(virus[i]);
                vis[virus[i].first][virus[i].second] = 0;
            }
        }

        while (q.size()) {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (vis[nx][ny] != -1 || arr[nx][ny] == 1) continue;

                q.push({nx, ny});
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
            }
        }

        int cnt = 0;
        int infect_place = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt = max(cnt, vis[i][j]);
                if (vis[i][j] != -1) {
                    infect_place++;
                }
            }
        }

        if (infect_place == total_place + v.size()) {
            ans = min(ans, cnt);
        }
    } while (next_permutation(v.begin(), v.end()));

    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
