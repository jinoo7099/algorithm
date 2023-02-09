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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;

    while (1) {
        int t;
        cin >> t;
        if (t == 0) {
            break;
        }

        int a[100002][4];
        int d[100002][4];
        for (int i = 1; i <= t; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> a[i][j];
            }
        }

        d[1][1] = 0;
        d[1][2] = a[1][2];
        d[1][3] = a[1][2] + a[1][3];

        for (int i = 2; i <= t; i++) {
            if (i == 2) {
                d[i][1] = d[i - 1][2] + a[i][1];
                d[i][2] = min({d[i - 1][2], d[i - 1][3], d[i][1]}) + a[i][2];
                d[i][3] = min({d[i - 1][2], d[i - 1][3], d[i][2]}) + a[i][3];
            } else {
                d[i][1] = min({d[i - 1][1], d[i - 1][2]}) + a[i][1];
                d[i][2] = min({d[i - 1][1], d[i - 1][2], d[i - 1][3], d[i][1]}) + a[i][2];
                d[i][3] = min({d[i - 1][2], d[i - 1][3], d[i][2]}) + a[i][3];
            }
        }

        cout << k++ << ". " << d[t][2] << endl;
    }

    return 0;
}
