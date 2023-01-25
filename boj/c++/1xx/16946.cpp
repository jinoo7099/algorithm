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
int d[1002][1002];
int vis[1002][1002];
int group[1002][1002];
vector<int> group_size;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            d[i][j] = s[j] - '0';
            group[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] == 0 && vis[i][j] == 0) {
                queue<pair<int, int>> q;
                int g = group_size.size();
                q.push({i, j});
                vis[i][j] = 1;
                group[i][j] = g;

                int cnt = 1;

                while (q.size()) {
                    auto cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                        if (d[nx][ny] == 0 && vis[nx][ny] == 0) {
                            q.push({nx, ny});
                            vis[nx][ny] = 1;
                            group[nx][ny] = g;
                            cnt++;
                        }
                    }
                }

                group_size.push_back(cnt);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] == 0) {
                cout << 0;
            } else {
                set<int> s;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                        if (d[nx][ny] == 0) {
                            s.insert(group[nx][ny]);
                        }
                    }
                }
                int ans = 1;
                for (int g : s) {
                    ans += group_size[g];
                }
                cout << ans % 10;
            }
        }
        cout << endl;
    }

    return 0;
}
