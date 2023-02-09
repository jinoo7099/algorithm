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

ll d[100];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    d[1] = 9;
    d[2] = 17;

    for (int i = 3; i <= n; i++) {
        int k = 1 << (i - 1);
        d[i] = (d[i - 1] - k) * 2 + k;
        d[i] %= 1000000000;
    }

    cout << d[n] << endl;

    return 0;
}
