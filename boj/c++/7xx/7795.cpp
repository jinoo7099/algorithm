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
        int n, m;
        cin >> n >> m;

        vector<pii> v(n + m);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v[i] = {a, 0};
        }
        for (int i = n; i < n + m; i++) {
            int b;
            cin >> b;
            v[i] = {b, 1};
        }
        sort(v.begin(), v.end());

        int cnt = 0;
        int ans = 0;

        for (int i = 0; i < n + m; i++) {
            if (v[i].second == 0) {
                ans += cnt;
            } else {
                cnt++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
