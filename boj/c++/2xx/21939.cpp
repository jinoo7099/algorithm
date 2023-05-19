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

    int n, m;
    cin >> n;

    // 난이도, 문제번호
    set<pair<int, int>> s;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;
        s.insert({l, p});
        mp[p] = l;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        string command;
        cin >> command;

        if (command == "add") {
            int p, l;
            cin >> p >> l;

            if (mp[p]) {
                s.erase({mp[p], p});
                s.insert({l, p});
            } else {
                mp[p] = l;
                s.insert({l, p});
            }
            /*
                1. 0 100
                2. 1000 3
                3. 1100 1

                lower_bound(1000, 0) -> 2
                lower_bound(1000, 2) -> 2
                lower_bound(0, 0) -> 1
                lower_bound(0, 50) -> 1
            */

        } else if (command == "solved") {
            int p;
            cin >> p;

            s.erase({mp[p], p});
        } else {
            int x;
            cin >> x;

            if (x == 1) {
                cout << (prev(s.end()))->second << endl;
            } else {
                cout << (s.begin())->second << endl;
            }
        }

        // cout << command << endl;
        // for (auto a : s) {
        //     cout << a.first << ' ' << a.second << endl;
        // }
        // cout << endl;
    }

    return 0;
}
