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

    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 2)
            b = n + m + n - b;
        else if (a == 3)
            b = 2 * n + m + m - b;
        else if (a == 4)
            b = n + b;
        v.push_back({a, b});
    }
    int ans = 0;

    for (int i = 0; i < k; i++) {
        int x = abs(v[k].second - v[i].second);
        ans += min(x, 2 * n + 2 * m - x);
    }

    cout << ans << endl;
    return 0;
}
