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

int d[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    d[1] = 1;
    d[2] = 3;

    for (int i = 3; i <= 1000; i++) {
        d[i] = d[i - 1] + 2 * d[i - 2];
        d[i] %= 10007;
    }

    int n;
    cin >> n;

    cout << d[n] << endl;
    return 0;
}
