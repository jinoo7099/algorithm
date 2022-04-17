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

int arr[200][200];
int res[200][200];
int op[1002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        cin >> op[i];
    }

    for (int i = 0; i < r; i++) {
        int rr = op[i];

        if (rr == 1) {
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < m; j++) {
                    res[i][j] = arr[n - i - 1][j];
                    res[n - i - 1][j] = arr[i][j];
                }
            }
        } else if (rr == 2) {
            for (int j = 0; j < m / 2; j++) {
                for (int i = 0; i < n; i++) {
                    res[i][j] = arr[i][m - j - 1];
                    res[i][m - j - 1] = arr[i][j];
                }
            }
        } else if (rr == 3) {
            int tmp = n;
            n = m;
            m = tmp;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res[i][j] = arr[m - 1 - j][i];
                }
            }

        } else if (rr == 4) {
            int tmp = n;
            n = m;
            m = tmp;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res[i][j] = arr[j][n - 1 - i];
                }
            }
        } else if (rr == 5) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i < n / 2 && j < m / 2) {
                        res[i][j] = arr[i + n / 2][j];
                    } else if (i < n / 2 && j >= m / 2) {
                        res[i][j] = arr[i][j - m / 2];
                    } else if (i >= n / 2 && j < m / 2) {
                        res[i][j] = arr[i][j + m / 2];
                    } else {
                        res[i][j] = arr[i - n / 2][j];
                    }
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i < n / 2 && j < m / 2) {
                        res[i][j] = arr[i][j + m / 2];
                    } else if (i < n / 2 && j >= m / 2) {
                        res[i][j] = arr[i + n / 2][j];
                    } else if (i >= n / 2 && j < m / 2) {
                        res[i][j] = arr[i - n / 2][j];
                    } else {
                        res[i][j] = arr[i][j - m / 2];
                    }
                }
            }
        }

        memcpy(arr, res, sizeof(arr));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
