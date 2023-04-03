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
int arr[52][52];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
int vis[22];
int ans = 1e9;

void solve(int cur, int k, int st) {
    if (cur == k) {
        int sum = 0;
        for (auto house : houses) {
            auto [x, y] = house;
            int minx = 1e9;
            for (int i = 0; i < chickens.size(); i++) {
                if (vis[i] == 0) continue;
                int dist = abs(x - chickens[i].first) + abs(y - chickens[i].second);
                minx = min(minx, dist);
            }
            sum += minx;
        }
        ans = min(ans, sum);
        return;
    }

    for (int i = st; i < chickens.size(); i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        solve(cur + 1, k, i + 1);
        vis[i] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) {
                houses.push_back({i, j});
            } else if (arr[i][j] == 2) {
                chickens.push_back({i, j});
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        solve(0, i, 0);
    }

    cout << ans << endl;

    return 0;
}
