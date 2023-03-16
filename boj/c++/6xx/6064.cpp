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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int l = lcm(m, n);
        bool flag = false;
        for (int ii = x; ii <= l; ii += m) {
            if (ii % n == y) {
                cout << ii << endl;
                flag = true;
            }
        }
        if (!flag) {
            cout << -1 << endl;
        }
    }
    return 0;
}
