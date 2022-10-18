#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);

        vector<int> res;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (i % 2 == 0) {
                sort(v.begin(), v.begin() + i + 1);

                res.push_back(v[i / 2]);
            }
        }
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
            if (i % 10 == 9) cout << endl;
        }
        cout << endl;
    }
    return 0;
}
