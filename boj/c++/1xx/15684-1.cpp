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

int n, m, h;
int arr[32][12];
int ans = 1e9;
bool is_finished = false;

bool checkMove() {
    for (int j = 1; j <= n; j++) {
        int y = j;
        for (int i = 1; i <= h; i++) {
            if (arr[i][y] == 1) {
                y += 1;
            } else if (arr[i][y - 1] == 1) {
                y -= 1;
            }
        }
        if (y != j) return false;
    }
    return true;
}

void dfs(int cur, int r, int c, int k) {
    if (cur == k) {
        if (checkMove())
            ans = min(ans, cur);
        return;
    }

    for (int i = r; i <= h; i++) {
        for (int j = c; j <= n - 1; j++) {
            if (arr[i][j]) continue;
            if (j + 1 <= n and arr[i][j + 1] == 1) continue;
            if (j - 1 >= 1 and arr[i][j - 1] == 1) continue;

            arr[i][j] = 1;
            dfs(cur + 1, i, j + 1, k);
            arr[i][j] = 0;
        }
        c = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    int k = 0;
    while (k < 4) {
        dfs(0, 1, 1, k);
        k++;
    }

    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
