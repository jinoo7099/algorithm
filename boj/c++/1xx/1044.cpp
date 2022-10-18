#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, res = 1e9;
int arr[2][40];

void solve(vector<pair<int, int>>& v, int asum, int bsum, int cur, int st, int end, int mask) {
    if (cur == end) {
        v.push_back({asum - bsum, mask});
        return;
    }
    if (end == n / 2) {
        solve(v, asum + arr[0][cur], bsum, cur + 1, st, end, (mask << 1));

        solve(v, asum, bsum + arr[1][cur], cur + 1, st, end, (mask << 1) + 1);
    } else {
        solve(v, asum + arr[0][cur], bsum, cur + 1, st, end, (mask << 1));

        solve(v, asum, bsum + arr[1][cur], cur + 1, st, end, (mask << 1) + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, int>> v1;
    vector<pair<int, int>> v2;

    solve(v1, 0, 0, 0, 0, n / 2, 0);
    solve(v2, 0, 0, n / 2, n / 2, n, 0);

    sort(v2.begin(), v2.end());

    for (auto a : v1) {
        cout << a.first << ' ' << a.second << endl;
    }

    for (auto a : v2) {
        cout << a.first << ' ' << a.second << endl;
    }

    int resMask1 = 1e9;
    int resMask2 = 1e9;
    for (int i = 0; i < v1.size(); i++) {
        pair<int, int> k = make_pair(-v1[i].first, 0);
        auto it = upper_bound(v2.begin(), v2.end(), k);
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        cout << ((resMask1 >> i) & 1) + 1 << ' ';
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        cout << ((resMask2 >> i) & 1) + 1 << ' ';
    }

    return 0;
}
