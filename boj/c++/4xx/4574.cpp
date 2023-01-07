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

int n;
int d[40][40];
string alpha = "ABCDEFGHI";

int vis1[52][52];
int vis2[52][52];
int vis3[52][52];

void go(int cur) {
    if (cur == n * n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    int x = cur / n;
    int y = cur % n;

    if (d[x][y]) {
        go(cur + 1);
    } else {
        cout << cur << endl;

        for (int i = 1; i <= 9; i++) {
            if (vis1[x][i] || vis2[y][i] || vis3[x / 3 * 3 + y / 3][i]) continue;

            vis1[x][i] = vis2[y][i] = vis3[x / 3 * 3 + y / 3][i] = 1;
            d[x][y] = i;
            go(cur + 1);
            d[x][y] = 0;
            vis1[x][i] = vis2[y][i] = vis3[x / 3 * 3 + y / 3][i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;

    while (1) {
        memset(d, 0, sizeof(d));
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        memset(vis3, 0, sizeof(vis3));
        cin >> n;
        if (n == 0) break;
        cout << "Puzzle " << cnt++ << endl;

        int u, v;
        string lu, lv;

        for (int i = 0; i < n; i++) {
            cin >> u >> lu >> v >> lv;
            int r1 = lu[0] - 'A';
            int c1 = lu[1] - '0';
            d[r1][c1] = u;

            int r2 = lv[0] - 'A';
            int c2 = lv[1] - '0';
            d[r2][c2] = v;
        }

        for (int i = 1; i <= 9; i++) {
            string t;
            cin >> t;
            int r = t[0] - 'A';
            int c = t[1] - '0';
            d[r][c] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << d[i][j] << " ";
                if (d[i][j]) {
                    vis1[i][d[i][j]] = 1;
                    vis2[j][d[i][j]] = 1;
                    vis3[i / 3 * 3 + j / 3][d[i][j]] = 1;
                }
            }
            cout << endl;
        }

        go(0);
    }

    return 0;
}
