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

int a[102][102];
int vis[102][102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    // 가로
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] == a[i][j + 1] - 1) {
                if (j - l + 1 < 0) {
                    flag = true;
                    break;
                }

                for (int k = j; k >= j - l + 1; k--) {
                    if (a[i][j] != a[i][k] || vis[i][k]) {
                        flag = true;
                        break;
                    }
                    vis[i][k] = 1;
                }
            } else if (a[i][j] == a[i][j + 1] + 1) {
                if (j + l >= n) {
                    flag = true;
                    break;
                }

                for (int k = j + 1; k <= j + l; k++) {
                    if (a[i][j + 1] != a[i][k] || vis[i][k]) {
                        flag = true;
                        break;
                    }
                    vis[i][k] = 1;
                }
            } else if (a[i][j] == a[i][j + 1]) {
                continue;
            } else {
                flag = true;
                break;
            }
        }

        if (!flag) {
            ans++;
        }
    }

    memset(vis, 0, sizeof(vis));
    // 세로
    for (int j = 0; j < n; j++) {
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i][j] == a[i + 1][j] - 1) {
                if (i - l + 1 < 0) {
                    flag = true;
                    break;
                }

                for (int k = i; k >= i - l + 1; k--) {
                    if (a[i][j] != a[k][j] || vis[k][j]) {
                        flag = true;
                        break;
                    }

                    vis[k][j] = 1;
                }
            } else if (a[i][j] == a[i + 1][j] + 1) {
                if (i + l >= n) {
                    flag = true;
                    break;
                }

                for (int k = i + 1; k <= i + l; k++) {
                    if (a[i + 1][j] != a[k][j] || vis[k][j]) {
                        flag = true;
                        break;
                    }

                    vis[k][j] = 1;
                }
            } else if (a[i][j] == a[i + 1][j]) {
                continue;
            } else {
                flag = true;
                break;
            }
        }

        if (!flag) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
