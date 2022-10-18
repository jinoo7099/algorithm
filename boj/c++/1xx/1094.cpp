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
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 6; i >= 0; i--) {
        int p = (1 << i);
        if (p <= x) {
            x -= p;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
