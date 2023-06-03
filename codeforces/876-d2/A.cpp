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
        double k;
        cin >> n >> k;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++) {
            int p = ceil(i / k);

            // left
            int l_cnt = 0;
            for (int j = 1; j <= i; j++) {
                if (a[j] == 1) l_cnt++;
            }
            if (l_cnt < p) {
                a[i] = 1;
            }

            int r_cnt = 0;
            // right
            for (int j = n; j > n - i; j--) {
                if (a[j] == 1) r_cnt++;
            }

            if (r_cnt < p) {
                a[n - i + 1] = 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
