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
int answer = 1e9;
int n, m, k;
char d[52][52];

int go(int cur, int x1, int y1, int x2, int y2) {
    if (cur == 11) {
        return -1;
    }
    bool fall1 = false;
    bool fall2 = false;

    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) fall1 = true;
    if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) fall2 = true;
    if (fall1 && fall2) return -1;
    if (fall1 || fall2) return cur;

    int ans = -1;
    for (int i = 0; i < 4; i++) {
        int nx1 = x1 + dx[i];
        int ny1 = y1 + dy[i];

        int nx2 = x2 + dx[i];
        int ny2 = y2 + dy[i];

        if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m && d[nx1][ny1] == '#') {
            nx1 = x1;
            ny1 = y1;
        }

        if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && d[nx2][ny2] == '#') {
            nx2 = x2;
            ny2 = y2;
        }

        int temp = go(cur + 1, nx1, ny1, nx2, ny2);
        if (temp == -1) continue;
        if (ans == -1 || ans > temp) {
            ans = temp;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int x1, y1, x2, y2;
    x1 = y1 = x2 = y2 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
            if (d[i][j] == 'o') {
                if (x1 == -1) {
                    x1 = i;
                    y1 = j;
                } else {
                    x2 = i;
                    y2 = j;
                }
                d[i][j] = '.';
            }
        }
    }

    cout << go(0, x1, y1, x2, y2) << endl;

    return 0;
}
