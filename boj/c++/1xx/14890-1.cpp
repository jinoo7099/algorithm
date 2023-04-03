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

int n, l;
int arr[102][102];
int is_created[102][102];
int ans;

void rotate() {
    int tmp[102][102];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            tmp[i][j] = arr[j][n - i + 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

void checkRow() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        bool ch = true;
        for (int j = 1; j < n; j++) {
            if (arr[i][j] != arr[i][j + 1]) {
                if (abs(arr[i][j] - arr[i][j + 1]) != 1) {
                    ch = false;
                    break;
                }

                int low_idx = (arr[i][j] < arr[i][j + 1]) ? j : j + 1;
                int high_idx = (arr[i][j] < arr[i][j + 1]) ? j + 1 : j;
                int low_val = arr[i][low_idx];

                if (low_idx < high_idx) {
                    for (int k = low_idx; k != low_idx - l; k--) {
                        if (low_val != arr[i][k] || is_created[i][k]) {
                            ch = false;
                            break;
                        }
                        is_created[i][k] = 1;
                    }
                } else {
                    for (int k = low_idx; k != low_idx + l; k++) {
                        if (low_val != arr[i][k] || is_created[i][k]) {
                            ch = false;
                            break;
                        }
                        is_created[i][k] = 1;
                    }
                }
            }
            if (!ch) break;
        }
        if (ch) {
            sum++;
        }
    }

    ans += sum;
}

void solve() {
    checkRow();
    rotate();
    memset(is_created, 0, sizeof(is_created));
    checkRow();

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    solve();

    return 0;
}
