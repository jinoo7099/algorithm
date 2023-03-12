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

int n;
int arr[20][20];
int vis[20][20];
int ans;

void solve(int x, int y, int mode) {
    if (x < 1 || x > n || y < 1 || y > n) return;
    if (x == n and y == n) {
        ans++;
        return;
    }

    if (mode == 0 || mode == 2) {
        if (arr[x][y + 1] == 0) {
            vis[x][y + 1] = 1;
            solve(x, y + 1, 0);
            vis[x][y + 1] = 0;
        }
    }

    if (mode == 1 || mode == 2) {
        if (arr[x + 1][y] == 0) {
            vis[x + 1][y] = 1;
            solve(x + 1, y, 1);
            vis[x + 1][y] = 0;
        }
    }

    if (arr[x + 1][y + 1] == 0 and arr[x + 1][y] == 0 and arr[x][y + 1] == 0) {
        vis[x + 1][y + 1] = 1;
        solve(x + 1, y + 1, 2);
        vis[x + 1][y + 1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    solve(1, 2, 0);

    cout << ans << endl;
    return 0;
}
