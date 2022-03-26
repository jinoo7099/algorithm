#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, k, l;
vector<vector<int>> arr(102, vector<int>(102, -1));
char dir[10002];

void solve() {
    int x, y;
    int d = 0;
    int cnt = 0;
    int len = 1;

    x = y = 1;
    arr[x][y] = cnt;

    while (cnt <= 10000) {
        cnt++;

        x += dx[d];
        y += dy[d];

        if (x < 1 || x > n || y < 1 || y > n) break;
        if (arr[x][y] != -1 && arr[x][y] >= cnt - len) break;
        if (arr[x][y] == -2) len++;

        if (dir[cnt] == 'D') d = (d + 1) % 4;
        if (dir[cnt] == 'L') d = (d + 3) % 4;

        arr[x][y] = cnt;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = -2;
    }

    cin >> l;

    for (int i = 0; i < l; i++) {
        int a;
        char c;
        cin >> a >> c;

        dir[a] = c;
    }

    solve();
    return 0;
}
