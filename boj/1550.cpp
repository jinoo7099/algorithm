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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    ll res = 0;
    ll d = 1;
    for (int i = str.size() - 1; i >= 0; i--) {
        char c = str[i];
        if (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F')
            res += (c - 'A' + 10) * d;
        else
            res += (c - '0') * d;
        d *= 16;
    }
    cout << res << endl;
    return 0;
}
