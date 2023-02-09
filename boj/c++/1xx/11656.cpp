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

    string s;
    cin >> s;
    vector<string> v;

    for (int i = 0; i < s.size(); i++) {
        v.push_back(s.substr(i));
    }

    sort(v.begin(), v.end());

    for (auto a : v) {
        cout << a << endl;
    }

    return 0;
}
