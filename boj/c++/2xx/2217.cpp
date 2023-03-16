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

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max({ans, (n - i) * v[i], v[i]});
    }

    cout << ans << endl;
    return 0;
}
