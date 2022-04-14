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

    vector<pair<int, int>> v;
    vector<int> res(1001);

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v.push_back({val, i});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        res[v[i].second] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}
