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

int vis[2002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        memset(vis, 0, sizeof(vis));
        int n;
        cin >> n;

        int sang_x, sang_y;
        int en_x, en_y;

        cin >> sang_x >> sang_y;
        vector<pair<int, int>> markets;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            markets.push_back({x, y});
        }

        cin >> en_x >> en_y;

        queue<pair<int, int>> q;
        q.push({sang_x, sang_y});

        bool flag = false;
        while (q.size()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (abs(x - en_x) + abs(y - en_y) <= 1000) {
                flag = true;
                break;
            };

            for (int i = 0; i < n; i++) {
                if (vis[i]) continue;
                int d = abs(x - markets[i].first) + abs(y - markets[i].second);

                if (d <= 1000) {
                    vis[i] = true;
                    q.push({markets[i].first, markets[i].second});
                }
            }
        }

        if (flag) {
            cout << "happy" << endl;
        } else {
            cout << "sad" << endl;
        }
    }
    return 0;
}
