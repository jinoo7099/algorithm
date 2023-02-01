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

    int s, t;
    cin >> s >> t;
    if (s == t) {
        cout << 0 << endl;
        return 0;
    }

    queue<pair<ll, string>> q;
    vector<string> ans;
    unordered_map<ll, bool> mp;

    q.push({s, ""});
    mp[s] = 1;

    while (q.size()) {
        auto cur = q.front();
        ll x = cur.first;
        string s = cur.second;
        q.pop();
        if (x == t) {
            ans.push_back(s);
        }

        if (1 <= x * x && x * x <= 1e9 && !mp[x * x]) {
            q.push({x * x, s + "*"});
            mp[x * x] = 1;
        }
        if (1 <= x + x && x + x <= 1e9 && !mp[x + x]) {
            q.push({x + x, s + "+"});
            mp[x + x] = 1;
        }
        if (x > 0 && !mp[x - x]) {
            q.push({x - x, s + "-"});
            mp[x - x] = 1;
        }
        if (x && !mp[x / x]) {
            q.push({x / x, s + "/"});
            mp[x / x] = 1;
        }
    }

    sort(ans.begin(), ans.end(), [](string& s1, string& s2) {
        if (s1.length() != s2.length()) return s1.length() < s2.length();
        return s1 < s2;
    });

    if (ans.size()) {
        cout << ans[0] << endl;

    } else {
        cout << -1 << endl;
    }

    return 0;
}
