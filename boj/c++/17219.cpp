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

map<string, string> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (n--) {
        string site, pwd;
        cin >> site >> pwd;
        mp[site] = pwd;
    }

    while (m--) {
        string str;
        cin >> str;
        cout << mp[str] << endl;
    }
    return 0;
}
