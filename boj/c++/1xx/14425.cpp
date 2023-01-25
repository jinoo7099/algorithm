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

    unordered_map<string, int> mp;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[s] = 1;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (mp[s]) {
            ans += 1;
        }
    }
    cout << ans << endl;

    return 0;
}
