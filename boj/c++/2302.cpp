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
int ch[42];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a;
        cin >> a;
        ch[a - 1] = 1;
    }

    int ans = 1;

    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || ch[i]) {
            if (cnt == 2 || cnt == 1) {
                ans *= cnt;
            } else {
                ans *= (2 * (cnt - 2) + 1);
            }
            cnt = 0;
        } else {
            cnt++;
        }
    }
    sadsd
            cout
        << ans << endl;
    return 0;
}
