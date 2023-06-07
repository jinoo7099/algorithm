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

void solve() {
    int n;
    cin >> n;

    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        mp[str] += 1;
    }

    vector<string> v;
    for (auto x : mp) {
        for (int i = 0; i < x.second; i++) {
            if (i == 3) break;
            v.push_back(x.first);
        }
    }

    int ans = 1e9;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            for (int k = j + 1; k < v.size(); k++) {
                int sum = 0;

                for (int d = 0; d < 4; d++) {
                    if (v[i][d] != v[j][d]) sum++;
                    if (v[j][d] != v[k][d]) sum++;
                    if (v[k][d] != v[i][d]) sum++;
                }

                ans = min(ans, sum);
            }
        }
    }
    if (ans == 1e9)
        cout << 0 << endl;
    else
        cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    cin >> tt;
    while (tt--) solve();

    return 0;
}
