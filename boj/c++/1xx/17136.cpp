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

int n = 10;
int arr[22][22];
int vis[22][22];
int total_area;
int paper_cnt[6] = {5, 5, 5, 5, 5, 5};
int ans = 1e9;

bool check(int k, int x, int y) {
    for (int i = x; i < x + k; i++) {
        for (int j = y; j < y + k; j++) {
            if (arr[i][j] == 0 || i > n || j > n) {
                return false;
            }
        }
    }

    return true;
}

void fill(int k, int x, int y, int val) {
    for (int i = x; i < x + k; i++) {
        for (int j = y; j < y + k; j++) {
            arr[i][j] = val;
        }
    }
}

void dfs(int r, int c, int depth) {
    bool ch = false;
    for (int i = r; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 1) {
                r = i;
                c = j;
                ch = true;
                break;
            }
        }
        if (ch) break;
    }

    if (!ch) {
        ans = min(ans, depth);
        return;
    }

    for (int i = 1; i <= 5; i++) {
        if (paper_cnt[i] == 0)
            continue;
        if (!check(i, r, c)) continue;

        // cout << i << " " << x << " " << y << endl;
        fill(i, r, c, 0);
        paper_cnt[i]--;

        dfs(r, c, depth + 1);

        fill(i, r, c, 1);
        paper_cnt[i]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    dfs(1, 1, 0);

    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
