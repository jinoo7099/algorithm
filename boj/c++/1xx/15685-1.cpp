#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

int arr[112][112];
vector<int> dirs;
int x, y, d, g;

void makeCurve() {
    int s = dirs.size();

    for (int i = s - 1; i >= 0; i--) {
        int nxt_d = (dirs[i] + 1) % 4;
        x += dx[nxt_d];
        y += dy[nxt_d];
        arr[x][y] = 1;

        dirs.push_back(nxt_d);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> y >> x >> d >> g;

        dirs.clear();

        arr[x][y] = 1;
        x += dx[d];
        y += dy[d];
        arr[x][y] = 1;

        dirs.push_back(d);

        for (int i = 0; i < g; i++) {
            makeCurve();
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (arr[i][j] and arr[i + 1][j] and arr[i][j + 1] and arr[i + 1][j + 1]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
