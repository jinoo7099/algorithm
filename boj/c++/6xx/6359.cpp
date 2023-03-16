#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bool> rooms(n + 1, true);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                rooms[j] = !rooms[j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!rooms[i]) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
