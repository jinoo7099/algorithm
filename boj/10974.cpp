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

int res[10];
int vis[10];
int n;

void solve(int cur) {
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            cout << res[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        vis[i] = 1;
        res[cur] = i + 1;
        solve(cur + 1);
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    solve(0);

    return 0;
}
