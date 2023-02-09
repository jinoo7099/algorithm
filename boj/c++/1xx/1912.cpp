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

int d[100002];
int arr[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    d[0] = arr[0];
    for (int i = 1; i < n; i++) {
        d[i] = max(d[i - 1] + arr[i], arr[i]);
    }
    cout << *max_element(d, d + n) << endl;
    return 0;
}
