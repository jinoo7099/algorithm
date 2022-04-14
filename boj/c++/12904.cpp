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

string s, t;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;

    while (1) {
        if (s.size() == t.size()) break;
        string tmp = s;
        reverse(tmp.begin(), tmp.end());

        if (tmp == t.substr(0, tmp.size())) {
            tmp.push_back('B');
            s = tmp;
        } else {
            s.push_back('A');
        }

        // cout << s << endl;
    }

    if (s == t)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
