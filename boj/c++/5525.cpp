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

int n, m, ans;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s;

    int size = 2 * n + 1;
    for (int i = 0; i < m - size; i++) {
        int k = 0;
        if (s[i] == 'O') continue;

        while (s[i + 1] == 'O' & s[i + 2] == 'I') {
            k++;
            if (k == n) {
                k--;
                ans++;
            }
            i += 2;
        }
    }
    cout << ans << endl;
    return 0;
}
