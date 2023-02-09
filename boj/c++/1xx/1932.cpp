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

int arr[502][502];
int d[502][502];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    d[0][0] = arr[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                d[i][j] = d[i - 1][j] + arr[i][j];
            } else if (j == i) {
                d[i][j] = d[i - 1][j - 1] + arr[i][j];
            } else {
                d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + arr[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, d[n - 1][i]);
    }
    cout << ans << endl;
    return 0;
}
