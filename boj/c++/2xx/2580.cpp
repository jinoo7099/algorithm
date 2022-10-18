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

// 가로, 세로, 3*3
int vis1[10][10];
int vis2[10][10];
int vis3[10][10];
int arr[10][10];
int n = 9;
int cnt;
vector<pair<int, int>> co;
int ch[10][10][10];
asdasd void solve(int cur, int val) {
    if (cur == co.size()) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
        return;
    }
    for (int c = val; c < co.size(); c++) {
        int i = co[c].X;
        int j = co[c].Y;
        for (int k = 1; k <= 9; k++) {
            if (vis1[i][k] || vis2[j][k] || vis3[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][k])
                continue;
            vis1[i][k] = 1;
            vis2[j][k] = 1;
            vis3[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][k] = 1;
            arr[i][j] = k;
            solve(cur + 1, c + 1);
            arr[i][j] = 0;
            vis1[i][k] = 0;
            vis2[j][k] = 0;
            vis3[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][k] = 0;
        }
    }

    // for (int i = 1; i <= 9; i++) {
    //     for (int j = 1; j <= 9; j++) {
    //         if (arr[i][j]) continue;

    //         for (int k = 1; k <= 9; k++) {
    //             if (vis1[i][k] || vis2[j][k] || vis3[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][k])
    //                 continue;
    //             vis1[i][k] = 1;
    //             vis2[j][k] = 1;
    //             vis3[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][k] = 1;
    //             arr[i][j] = k;
    //             solve(cur + 1);
    //             arr[i][k] = 0;
    //             vis1[i][k] = 0;
    //             vis2[j][k] = 0;
    //             vis3[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][k] = 0;
    //         }
    //     }
    // }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> arr[i][j];
            vis1[i][arr[i][j]] = 1;
            vis2[j][arr[i][j]] = 1;
            vis3[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][arr[i][j]] = 1;
            if (arr[i][j])
                cnt++;
            else
                co.push_back({i, j});
        }
    }

    solve(0, 0);
    return 0;
}
