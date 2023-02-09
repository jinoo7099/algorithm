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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), [&](string a, string b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto a : v) {
        cout << a << endl;
    }

    return 0;
}
