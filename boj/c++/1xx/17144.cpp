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

int airx, airy;

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
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j]) {
                    int cnt = 0;

                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                        if (a[nx][ny] == -1) continue;

                        a[nx][ny] += a[i][j] / 5;
                        cnt++;
                    }

                    a[i][j] -= a[i][j] / 5 * cnt;
                }
            }
        }

        // 공기청정기
        for(int i=0)
    }
    return 0;
}
