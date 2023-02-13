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

int arr[100002];
int d[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    d[0] = 1;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        for (int j = a; j <= k; j++) {
            d[j] += d[j - a];
        }
    }

    cout << d[k] << endl;
    return 0;
}
