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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            bool st, en;
            st = en = false;

            int st_len = (x1 - a) * (x1 - a) + (y1 - b) * (y1 - b);
            if (st_len <= c * c) st = true;

            int en_len = (x2 - a) * (x2 - a) + (y2 - b) * (y2 - b);
            if (en_len <= c * c) en = true;

            if (st && en) continue;

            if (st) ans++;
            if (en) ans++;
        }

        cout << ans << endl;
    }
    return 0;
}
