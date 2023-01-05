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

void solve(int cur) {
    if (cur == s) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j]) continue;

            for (int k = 1; k <= 9; k++) {
                if (vis1[i][k] || vis2[j][k] || vis3[i / 3 * 3 + j % 3][k]) continue;

                vis1[i][k] = 1;
                vis2[j][k] = 1;
                vis3[i / 3 * 3 + j % 3][k] = 1;
                d[i][j] = k;
                solve(cur + 1);
                vis1[i][k] = 0;
                vis2[j][k] = 0;
                vis3[i / 3 * 3 + j % 3][k] = 0;
                d[i][j] = 0;
            }
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
            } else {
                s++;
            }
        }
    }

    solve(0);

    return 0;
}
