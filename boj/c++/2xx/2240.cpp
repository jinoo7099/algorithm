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

int d[3][1002][32];
int arr[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, w;
    cin >> t >> w;

    for (int i = 1; i <= t; i++) {
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= w + 1; j++) {
            if (arr[i] == 1) {
                d[1][i][j] = max(d[1][i - 1][j], d[2][i - 1][j - 1]) + 1;
                d[2][i][j] = max(d[2][i - 1][j], d[1][i - 1][j - 1]);
            } else {
                if (i == 1 && j == 1) continue;
                d[1][i][j] = max(d[1][i - 1][j], d[2][i - 1][j - 1]);
                d[2][i][j] = max(d[2][i - 1][j], d[1][i - 1][j - 1]) + 1;
            }
        }
    }

    for (int i = 1; i <= w + 1; i++) {
        ans = max({ans, d[1][t][i], d[2][t][i]});
    }

    cout << ans << endl;

    return 0;
}
