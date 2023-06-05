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
    cin >> n;

    int d = 0;
    int k = n;
    while (k) {
        k /= 10;
        d++;
    }

    if (d <= 3) {
        cout << n << endl;
    } else if (d == 4) {
        cout << n / 10 * 10 << endl;
    } else if (d == 5) {
        cout << n / 100 * 100 << endl;
    } else if (d == 6) {
        cout << n / 1000 * 1000 << endl;
    } else if (d == 7) {
        cout << n / 10000 * 10000 << endl;
    } else if (d == 8) {
        cout << n / 100000 * 100000 << endl;
    } else if (d == 9) {
        cout << n / 1000000 * 1000000 << endl;
    }

    return 0;
}
