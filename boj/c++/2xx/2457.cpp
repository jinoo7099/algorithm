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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<pair<int, int>> flowers;

    for (int i = 0; i < n; i++) {
        int st_month, st_day, en_month, en_day;
        cin >> st_month >> st_day >> en_month >> en_day;
        flowers.push_back({st_month * 100 + st_day, en_month * 100 + en_day});
    }

    int t = 301;
    int ans = 0;
    while (t < 1201) {
        int nxt_t = t;
        for (int i = 0; i < n; i++) {
            if (flowers[i].first <= t and flowers[i].second > nxt_t) {
                nxt_t = flowers[i].second;
            }
        }
        if (nxt_t == t) {
            cout << 0 << endl;
            return 0;
        }

        ans++;
        t = nxt_t;
    }
    cout << ans << endl;

    return 0;
}
