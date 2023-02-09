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

    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        d[i] = arr[i];
    }

    d[0] = arr[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                d[i] = max(d[i], d[j] + arr[i]);
            }
        }
    }
    cout << *max_element(d, d + n) << endl;
    return 0;
}
