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

    int m, n;
    cin >> m >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll st, en;
    st = 0;
    en = a[a.size() - 1];

    while (st < en) {
        ll mid = (st + en + 1) / 2;
        ll cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += a[i] / mid;
        }

        if (cnt >= m) {
            st = mid;
        } else {
            en = mid - 1;
        }
    }

    cout << st << endl;

    return 0;
}
