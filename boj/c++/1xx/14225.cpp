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
vector<int> res;
void solve(int cur, vector<int> a, int sum) {
    if (cur == a.size()) {
        res.push_back(sum);
        return;
    }

    solve(cur + 1, a, sum);

    solve(cur + 1, a, sum + a[cur]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res.push_back(a[i]);
    }

    solve(0, a, 0);

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    int i = 1;
    while (1) {
        if (i != res[i]) {
            cout << i;
            break;
        }
        i++;
    }

    return 0;
}
