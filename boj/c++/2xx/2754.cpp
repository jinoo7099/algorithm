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

    map<string, string> mp;

    mp["A+"] = "4.3";
    mp["A0"] = "4.0";
    mp["A-"] = "3.7";
    mp["B+"] = "3.3";
    mp["B0"] = "3.0";
    mp["B-"] = "2.7";
    mp["C+"] = "2.3";
    mp["C0"] = "2.0";
    mp["C-"] = "1.7";
    mp["D+"] = "1.3";
    mp["D0"] = "1.0";
    mp["D-"] = "0.7";
    mp["F"] = "0.0";

    string s;
    cin >> s;
    cout << mp[s] << endl;

    return 0;
}
