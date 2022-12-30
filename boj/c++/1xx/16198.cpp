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

int ans;

void solve(vector<int> a, int sum) {
    if (a.size() == 2) {
        ans = max(ans, sum);
        return;
    }

    for (int i = 1; i < a.size() - 1; i++) {
        vector<int> tmp = a;

        int k = tmp[i - 1] * tmp[i + 1];
        int g = tmp[i];
        tmp.erase(tmp.begin() + i);
        solve(tmp, sum + k);
        tmp.insert(tmp.begin() + i, g);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    solve(a, 0);

    cout << ans << endl;

    return 0;
}
