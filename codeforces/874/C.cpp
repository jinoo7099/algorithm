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
        int n;
        bool isAns = true;
        bool isEven = true;
        bool isOdd = true;

        int minEven = 1e9;
        int minOdd = 1e9;

        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (a[i] % 2 == 0) {
                isOdd = false;
                minEven = min(minEven, a[i]);
            } else {
                isEven = false;
                minOdd = min(minOdd, a[i]);
            }
        }

        if (isEven || isOdd) {
            cout << "YES" << endl;
            continue;
        }

        // all to even
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1) {
                if (a[i] - minOdd < 0) {
                    isAns = false;
                    break;
                }
            }
        }

        // all to odd
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                if (a[i] - minOdd < 0) {
                    isAns = false;
                    break;
                }
            }
        }

        if (isAns)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
