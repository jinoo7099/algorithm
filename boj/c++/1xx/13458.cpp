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

int n;
int b, c;
int arr[1000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> b >> c;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        arr[i] -= b;
        ans++;
        if (arr[i] <= 0) continue;

        ans += (arr[i] % c == 0) ? arr[i] / c : arr[i] / c + 1;
    }

    cout << ans << endl;

    return 0;
}
