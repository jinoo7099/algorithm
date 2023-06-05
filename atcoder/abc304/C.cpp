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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> v;
    int vis[2002] = {
        0,
    };
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while (q.size()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (cur == i) continue;

            int distance = abs(v[cur].first - v[i].first) * abs(v[cur].first - v[i].first) + abs(v[cur].second - v[i].second) * abs(v[cur].second - v[i].second);

            if (distance <= d * d) {
                q.push(i);
                vis[i] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
