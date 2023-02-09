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

int arr[10002];
int d[10002][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    d[1][1] = arr[1];

    for (int i = 2; i <= n; i++) {
        d[i][0] = max({d[i - 1][0], d[i - 1][1], d[i - 1][2]});
        d[i][1] = d[i - 1][0] + arr[i];
        d[i][2] = d[i - 1][1] + arr[i];
    }

    cout << max({d[n][0], d[n][1], d[n][2]}) << endl;

    return 0;
}
