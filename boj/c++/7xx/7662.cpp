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
        int k;
        cin >> k;

        multiset<int> s;

        for (int i = 0; i < k; i++) {
            char c;
            int num;

            cin >> c >> num;

            if (c == 'D') {
                if (s.size() == 0) continue;

                if (num == 1) {
                    auto it = --s.end();
                    s.erase(it);
                } else {
                    s.erase(s.begin());
                }
            } else {
                s.insert(num);
            }
        }

        if (s.size() == 0) {
            cout << "EMPTY" << endl;
        } else {
            cout << *(--s.end()) << ' ' << *s.begin() << endl;
        }
    }

    return 0;
}
