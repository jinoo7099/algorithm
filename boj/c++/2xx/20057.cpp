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

int n;
int arr[502][502];
int ans;

int row[4][10] = {
    // 0
    {0, 0, -1, -1, -1, -1, -2, -2, -3, -2},
    // 1
    {1, -1, 1, -1, 2, -2, 1, -1, 0, 0},
    // 2
    {0, 0, 1, 1, 1, 1, 2, 2, 3, 2},
    // 3
    {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0},
};
int col[4][10] = {
    // 0
    {1, -1, 1, -1, 2, -2, 1, -1, 0, 0},
    // 1
    {0, 0, 1, 1, 1, 1, 2, 2, 3, 2},
    // 2
    {1, -1, 1, -1, -2, 2, -1, 1, 0, 0},
    // 3
    {0, 0, -1, -1, -1, -1, -2, -2, -3, -2},
};
int percents[] = {1, 1, 7, 7, 2, 2, 10, 10, 5};

void spread(int x, int y, int d) {
    int xx = x + dx[d];
    int yy = y + dy[d];
    if (arr[xx][yy] == 0) return;

    int sand = arr[xx][yy];
    int tmp = sand;

    for (int i = 0; i < 9; i++) {
        int nx = x + row[d][i];
        int ny = y + col[d][i];
        int val = (tmp * percents[i]) / 100;

        if (nx < 1 || nx > n || ny < 1 || ny > n) {
            ans += val;
        } else {
            arr[nx][ny] += val;
        }

        sand -= val;
    }

    int nx = x + row[d][9];
    int ny = y + col[d][9];

    if (nx < 1 || nx > n || ny < 1 || ny > n) {
        ans += sand;
    } else {
        arr[nx][ny] += sand;
    }
    arr[xx][yy] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    int x = (n + 1) / 2;
    int y = (n + 1) / 2;
    int d = 3;
    int cnt = 1;

    while (1) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < cnt; j++) {
                spread(x, y, d);

                x = x + dx[d];
                y = y + dy[d];
            }

            d = (d - 1 + 4) % 4;
        }
        cnt++;
        if (cnt == n) {
            for (int j = 0; j < cnt; j++) {
                spread(x, y, d);

                x = x + dx[d];
                y = y + dy[d];
            }
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
