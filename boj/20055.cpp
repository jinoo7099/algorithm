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

vector<pair<int, int>> arr;
int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    arr = vector<pair<int, int>>(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        int a;
        cin >> a;
        arr[i] = {a, 0};
    }
    int ans = 0;

    while (1) {
        ans++;
        // 1
        auto tmp = arr[2 * n - 1];
        for (int i = 2 * n - 1; i > 0; i--) {
            // n - 1번째 로봇 내리기
            if (i == n - 1) {
                arr[i - 1].second = 0;
            }
            arr[i] = arr[i - 1];
        }
        arr[0] = tmp;

        // 2
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i].second == 1 && arr[i + 1].first > 0 && arr[i + 1].second == 0) {
                if (i == n - 2) {
                    // n - 1번째 로봇 내리기
                    arr[i + 1].first--;
                    arr[i + 1].second = 0;

                    arr[i].second = 0;
                } else {
                    arr[i + 1].first--;
                    arr[i + 1].second = 1;

                    arr[i].second = 0;
                }
            }
        }

        // 3
        if (arr[0].first > 0) {
            arr[0].second = 1;
            arr[0].first -= 1;
        }

        // 4
        int cnt = 0;
        for (int i = 0; i < 2 * n; i++) {
            // cout << arr[i].first << ' ';
            if (arr[i].first == 0) cnt++;
        }
        // cout << endl;
        if (cnt >= k) {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
