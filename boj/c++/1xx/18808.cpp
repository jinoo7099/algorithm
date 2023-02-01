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

int n, m, k;
int steaker[42][42];
int d[42][42];
int r, c;
bool pastable(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (d[x + i][y + j] == 1 && steaker[i][j] == 1)
                return false;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (steaker[i][j] == 1)
                d[x + i][y + j] = 1;
        }
    }
    return true;
}

void rotate() {
    int tmp[12][12];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[i][j] = steaker[i][j];
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            steaker[i][j] = tmp[r - 1 - j][i];
        }
    }
    swap(r, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> steaker[i][j];
            }
        }

        for (int rot = 0; rot < 4; rot++) {
            bool is_paste = false;  // 해당 스티커를 붙였는가?
            for (int x = 0; x <= n - r; x++) {
                if (is_paste) break;
                for (int y = 0; y <= m - c; y++) {
                    if (pastable(x, y)) {
                        is_paste = true;
                        break;
                    }
                }
            }
            if (is_paste) break;
            rotate();
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt += d[i][j];
        }
    }
    cout << cnt << endl;
    return 0;
}
