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

int n, m, ans = 1e9;
int val;
bool arr[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        arr[a] = 1;
    }

    if (n == 100) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i <= 1000000; i++) {
        int tmp = i;
        bool check = false;

        do {
            int d = tmp % 10;

            if (arr[d] == 1) {
                check = true;
                break;
            }

            tmp /= 10;
        } while (tmp);

        if (!check && ans > abs(n - i)) {
            ans = abs(n - i);
            val = i;
        }
    }
    ans += to_string(val).size();
    ans = min(ans, abs(n - 100));
    cout << ans << endl;

    return 0;
}
