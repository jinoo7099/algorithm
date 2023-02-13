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

int adj[52][52];  // 왼쪽 가로선 -1 오른쪽 가로선 1
int ans = 1e9;

bool check() {
    for (int i = 1; i <= n; i++) {
        int col = i;

        for (int j = 1; j <= h; j++) {
            int row = j;

            if (adj[row][col]) {
                col++;
            } else if (0 < col && adj[row][col - 1]) {
                col--;
            }
        }
        if (col != i)
            return false;
    }
    return true;
}

void make_line(int cur, int k, int x, int y) {
    if (cur == k) {
        bool res = check();

        if (res == true) {
            ans = min(ans, k);
        }
        return;
    }

    for (int i = x; i <= h; i++) {
        for (int j = y; j <= n - 1; j++) {
            int r = i;
            int c = j;

            if (adj[r][c] == 1) continue;
            if (c - 1 >= 1 and adj[r][c - 1] == 1) continue;
            if (c + 1 <= n and adj[r][c + 1] == 1) continue;

            adj[r][c] = 1;
            make_line(cur + 1, k, r, c);
            adj[r][c] = 0;
        }
        y = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> h;

    // b - b+1 , a행
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }

    int k = 0;

    while (k < 4) {
        make_line(0, k, 1, 1);
        k++;
    }

    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
