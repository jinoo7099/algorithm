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

    int n, q;
    cin >> n >> q;

    set<int> s;
    int cur = 1;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            s.insert(i);
        }
    }

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;

        if (k == 1) {
            int a;
            cin >> a;

            if (s.find(a) != s.end()) {
                s.erase(a);
            } else {
                s.insert(a);
            }

        } else if (k == 2) {
            int a;
            cin >> a;

            cur += a % n;
            if (cur % n == 0) {
                cur = n;
            } else {
                cur %= n;
            }
        } else if (k == 3) {
            auto it = s.lower_bound(cur);

            if (it == s.end()) {
                it = s.lower_bound(1);

                if (it == s.end()) {
                    cout << -1 << endl;
                } else {
                    cout << n - cur + *it << endl;
                }
            } else {
                cout << *it - cur << endl;
            }
        }
    }

    return 0;
}
