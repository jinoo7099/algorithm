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
int arr[3][100002];
int d[3][100002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> arr[i][j];
            }
        }

        d[1][1] = arr[1][1];
        d[2][1] = arr[2][1];
        d[1][2] = max(d[2][1] + arr[1][2], d[1][1]);
        d[2][2] = max(d[1][1] + arr[2][2], d[2][1]);

        for (int i = 3; i <= n; i++) {
            d[1][i] = max({d[2][i - 1], d[1][i - 2], d[2][i - 2]}) + arr[1][i];
            d[2][i] = max({d[1][i - 1], d[1][i - 2], d[2][i - 2]}) + arr[2][i];
        }

        cout << max(d[1][n], d[2][n]) << endl;
    }

    return 0;
}
