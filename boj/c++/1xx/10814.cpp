#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, string>> v(n);
    for (int i = 0; i < n; i++) {
        int a;
        string b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    stable_sort(v.begin(), v.end(), [&](pair<int, string> p1, pair<int, string> p2) {
        return p1.first < p2.first;
    });

    for (auto p : v) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
