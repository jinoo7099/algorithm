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

int d[1500002];
pair<int, int> arr[1500002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = n; i >= 1; i--) {
        if (i + arr[i].first <= n + 1) {
            d[i] = max(d[i + arr[i].first] + arr[i].second, d[i + 1]);
        } else
            d[i] = d[i + 1];
    }

    cout << *max_element(d, d + n + 1) << endl;
    return 0;
}
