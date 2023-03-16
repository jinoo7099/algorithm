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

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        a.push_back(c);
    }

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        b.push_back(c);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * b[n - 1 - i];
    }

    cout << ans << endl;

    return 0;
}
