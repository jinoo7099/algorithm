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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    if (a[0] % 2 == 1) cnt++;
    int en = 0;
    int ans = 0;

    for (int st = 0; st < n; st++) {
        while (en < n - 1 && cnt + a[en + 1] % 2 <= k) {
            en++;
            cnt += a[en] % 2;
        }

        ans = max(ans, en - st + 1 - cnt);
        cnt -= a[st] % 2;
    }

    cout << ans << endl;

    return 0;
}
