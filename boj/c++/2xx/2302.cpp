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

vector<int> v = {0};
int d[42];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int vv;
        cin >> vv;
        v.push_back(vv);
    }
    v.push_back(n + 1);

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;

    for (int i = 3; i <= n; i++)
        d[i] = d[i - 1] + d[i - 2];

    int ans = 1;
    for (int i = 1; i <= m + 1; i++) {
        ans *= d[v[i] - v[i - 1] - 1];
    }
    cout << ans << endl;

    return 0;
}
