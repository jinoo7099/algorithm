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

int n = 9;
int s;
int d[12][12];
int vis1[52][52];  // 가로
int vis2[52][52];  // 세로
int vis3[52][52];  // 칸

void solve(int z) {
    if (z == 81) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }

    int x = z / n;
    int y = z % n;

    if (d[x][y]) {
        solve(z + 1);
    } else {
        for (int i = 1; i <= 9; i++) {
            if (vis1[x][i] || vis2[y][i] || vis3[x / 3 * 3 + y / 3][i]) continue;

            vis1[x][i] = vis2[y][i] = vis3[x / 3 * 3 + y / 3][i] = 1;
            d[x][y] = i;
            solve(z + 1);
            d[x][y] = 0;
            vis1[x][i] = vis2[y][i] = vis3[x / 3 * 3 + y / 3][i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];

            if (d[i][j]) {
                int k = d[i][j];
                vis1[i][k] = 1;
                vis2[j][k] = 1;
                vis3[i / 3 * 3 + j / 3][k] = 1;
            }
        }
    }

    solve(0);

    return 0;
}
