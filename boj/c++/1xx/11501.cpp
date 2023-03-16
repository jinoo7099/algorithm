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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        ll ans = 0;
        int maxx = v[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (maxx < v[i]) {
                maxx = v[i];
            } else if (maxx > v[i]) {
                ans += maxx - v[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
