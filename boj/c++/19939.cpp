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

    int n, k;
    cin >> n >> k;

    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += i;
    }

    n -= sum;

    if (n < 0) {
        cout << -1 << endl;
    } else {
        if (n % k == 0) {
            cout << k - 1 << endl;
        } else {
            cout << k << endl;
        }
    }

    return 0;
}
