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

int r, c, t;
int a[1002][1002];
int tmp[1002][1002];

int airx, airy;

void moveRight() {
}

void move() {
    int x1, y1;
    x1 = airx;
    y1 = airy;

    for (int i = x1 - 1; i > 0; i--) {
        a[i][0] = a[i - 1][0];
    }

    for (int i = 0; i < c - 1; i++) {
        a[0][i] = a[0][i + 1];
    }

    for (int i = 0; i < x1; i++) {
        a[i][c - 1] = a[i + 1][c - 1];
    }

    for (int i = c - 1; i > 1; i--) {
        a[x1][i] = a[x1][i - 1];
    }

    a[x1][1] = 0;

    int x2, y2;
    x2 = airx + 1;
    y2 = airy;

    for (int i = x2 + 1; i < r - 1; i++) {
        a[i][0] = a[i + 1][0];
    }

    for (int i = 0; i < c - 1; i++) {
        a[r - 1][i] = a[r - 1][i + 1];
    }

    for (int i = r - 1; i >= x2; i--) {
        a[i][c - 1] = a[i - 1][c - 1];
    }

    for (int i = c - 1; i > 1; i--) {
        a[x2][i] = a[x2][i - 1];
    }

    a[x2][1] = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];

            if (a[i][j] == -1 && airx == 0) {
                airx = i;
                airy = j;
            }
        }
    }

    for (int s = 0; s < t; s++) {
        memset(tmp, 0, sizeof(tmp));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                tmp[i][j] = a[i][j];
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] != 0 && a[i][j] != -1) {
                    int cnt = 0;
                    int val = a[i][j] / 5;

                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                        if (a[nx][ny] == -1) continue;

                        tmp[nx][ny] += val;
                        cnt++;
                    }

                    tmp[i][j] -= val * cnt;
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                a[i][j] = tmp[i][j];
            }
        }

        move();
    }

    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == -1) continue;
            ans += a[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
