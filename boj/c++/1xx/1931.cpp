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

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({e, s});
    }

    sort(v.begin(), v.end());

    int t = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (v[i].second < t) continue;
        t = v[i].first;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
