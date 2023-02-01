// 못품
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

int n, m;
char d[12][12];

int r_x, r_y, b_x, b_y;
int e_x, e_y;
bool ret = true;
void go(int cur) {
    if (!ret) return;
    if (cur >= 10) {
        ret = false;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            for (int j = r_x; j >= 0; j--) {
                if (d[j][r_y] == '#') {
                    break;
                }
                r_x = j;
            }
            for (int j = b_x; j >= 0; j--) {
                if (d[j][b_y] == '#') {
                }
                b_x = j;
            }

        } else if (i == 1) {
        } else if (i == 2) {
        } else {
        }
        go(cur + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];

            if (d[i][j] == 'R') {
                r_x = i;
                r_y = j;
            } else if (d[i][j] == 'B') {
                b_x = i;
                b_y = j;
            } else if (d[i][j] == 'O') {
                e_x = i;
                e_y = j;
            }
        }
    }

    go(0);

    return 0;
}
