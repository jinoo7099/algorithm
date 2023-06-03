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

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<pair<int, int>> p_a(n);
        for (int i = 0; i < n; i++) {
            p_a[i] = {a[i], i};
        }

        sort(p_a.begin(), p_a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < n; i++) {
            p_a[i].first = b[i];
        }

        sort(p_a.begin(), p_a.end(), [](auto& p1, auto& p2) {
            return p1.second < p2.second;
        });

        for (int i = 0; i < n; i++) {
            cout << p_a[i].first << ' ';
        }
        cout << endl;
    }
    return 0;
}
