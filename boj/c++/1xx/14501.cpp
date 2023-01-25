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

int n;
vector<pair<int, int>> v;

int go(int cur) {
    if (cur > v.size()) {
        return 0;
    }

    int ans = 0;

    int a = go(cur + 1);

    auto c = v[cur];
    if (cur + c.second > v.size()) {
        int b = go(cur + c.first);
    }
    ans += max(a, c.second);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    v.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    cout << go(1);

    return 0;
}
