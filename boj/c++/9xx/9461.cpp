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

ll d[102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;
    d[5] = 2;

    for (int i = 6; i <= 100; i++) {
        d[i] = d[i - 1] + d[i - 5];
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << d[n] << endl;
    }

    return 0;
}
