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

int arr[22][22];
int n;

int sumToNumber(int x) {
    return x * (x + 1) / 2;
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
    // 400 * 10

    for (int i = 2; i <= n - 1; i++) {
        for (int j = 2; j <= n - 1; j++) {
            int r = i;
            int c = j;

            for (int d1 = 1; d1 <= n - 1; d1++) {
                for (int d2 = 1; d2 <= n - 1; d2++) {
                    int nx, ny;

                    // a1
                    if (c - d1 < 1) continue;
                    if (r + d1 > n) continue;

                    // a2
                    if (c + d2 > n) continue;
                    if (r + d2 > n) continue;

                    // a3
                    if (r + d1 > n) continue;

                    // a4
                }
            }
        }
    }

    return 0;
}
