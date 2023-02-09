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

ll d[2000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    const int HALF = 1000000;
    d[HALF] = 0;
    d[HALF + 1] = 1;
    d[HALF - 1] = 1;

    for (int i = 2; i <= 1000000; i++) {
        d[HALF + i] = (d[HALF + i - 1] + d[HALF + i - 2]) % 1000000000;
        d[HALF - i] = (d[HALF - i + 2] - d[HALF - i + 1]) % 1000000000;
    }

    int k = d[HALF + n];

    if (k == 0) {
        cout << 0 << endl;
    } else if (k > 0) {
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }
    cout << abs(k) % 1000000000 << endl;
    return 0;
}
