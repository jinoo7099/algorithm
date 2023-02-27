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

int arr[102][102];
int n;
int x, y, d, g;

vector<int> dir;

void makeCurve() {
    int s = dir.size();

    for (int i = s - 1; i >= 0; i--) {
        int dd = (dir[i] + 1) % 4;
        x = x + dx[dd];
        y = y + dy[dd];
        arr[x][y] = 1;

        dir.push_back(dd);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> y >> x >> d >> g;
        dir.clear();

        arr[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        arr[x][y] = 1;

        dir.push_back(d);

        for (int j = 0; j < g; j++) {
            makeCurve();
        }
    }
    int ans = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (arr[i][j] == 1 and arr[i][j + 1] == 1 and arr[i + 1][j] == 1 and arr[i + 1][j + 1] == 1) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
