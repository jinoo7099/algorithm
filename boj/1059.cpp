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

int arr[52];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, n;
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> arr[i];
    }
    cin >> n;
    sort(arr, arr + l);
    int st = lower_bound(arr, arr + l, n) - arr;
    int en = upper_bound(arr, arr + l, n) - arr;

    if (arr[st] == n) {
        cout << 0 << endl;
        return 0;
    }
    st--;
    // cout << st << ' ' << en << endl;
    int ans = 0;

    for (int i = arr[st] + 1; i <= arr[en] - 1; i++) {
        for (int j = i + 1; j <= arr[en] - 1; j++) {
            if (i <= n && n <= j) {
                ans++;
                cout << i << ' ' << j << endl;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
