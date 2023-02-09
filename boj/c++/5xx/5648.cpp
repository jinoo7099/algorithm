#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];

        string s = to_string(v[i]);
        reverse(s.begin(), s.end());

        v[i] = stoll(s);
    }

    sort(v.begin(), v.end());

    for (auto a : v) {
        cout << a << endl;
    }
    return 0;
}
