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
    ;

    int n;
    cin >> n;

    vector<pair<string, int>> v(n);
    int minx = 2e9;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        if (minx > v[i].second) {
            minx = v[i].second;
            idx = i;
        }
    }

    for (int i = idx; i < n; i++) {
        cout << v[i].first << endl;
    }
    for (int i = 0; i < idx; i++) {
        cout << v[i].first << endl;
    }

    return 0;
}
