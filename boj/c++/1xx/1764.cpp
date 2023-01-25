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

    string s;
    unordered_map<string, int> mp;
    for (int i = 0; i < n + m; i++) {
        cin >> s;
        mp[s] += 1;
    }
    vector<string> ans;
    for (auto m : mp) {
        if (m.second == 2) {
            ans.push_back(m.first);
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto a : ans) {
        cout << a << endl;
    }

    return 0;
}
