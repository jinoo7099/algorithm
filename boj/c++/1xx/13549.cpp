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

int vis[200002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < 100001; i++) {
        vis[i] = 1e9;
    }

    queue<int> q;
    q.push(n);
    vis[n] = 0;

    while (q.size()) {
        int cur = q.front();
        q.pop();

        if (cur == k) {
            cout << vis[k] << endl;
            break;
        }

        if (2 * cur < 100001 && vis[2 * cur] > vis[cur]) {
            q.push(2 * cur);
            vis[2 * cur] = vis[cur];
        }
        if (cur + 1 < 100001 && vis[cur + 1] > vis[cur] + 1) {
            q.push(cur + 1);
            vis[cur + 1] = vis[cur] + 1;
        }
        if (cur - 1 >= 0 && vis[cur - 1] > vis[cur] + 1) {
            q.push(cur - 1);
            vis[cur - 1] = vis[cur] + 1;
        }
    }

    return 0;
}
