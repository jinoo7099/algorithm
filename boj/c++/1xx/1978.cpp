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

    int n;
    int ans = 0;
    vector<bool> state(10001, true);

    state[1] = false;

    for (int i = 2; i * i <= 1001; i++) {
        if (!state[i]) continue;
        for (int j = i * i; j <= 1001; j += i) {
            state[j] = false;
        }
    }

    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (state[a]) ans++;
    }

    cout << ans << endl;

    return 0;
}
