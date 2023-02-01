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

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (auto &s : v) cin >> s.first >> s.second;

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
