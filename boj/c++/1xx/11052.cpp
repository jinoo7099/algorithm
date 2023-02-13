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

int arr[1002];
int d[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    d[1] = arr[1];
    d[2] = max(arr[2], arr[1] * 2);
    for (int i = 3; i <= n; i++) {
        d[i] = arr[i];
        for (int j = 1; j < i; j++) {
            d[i] = max(d[i], d[j] + d[i - j]);
        }
    }

    cout << d[n] << endl;

    return 0;
}
