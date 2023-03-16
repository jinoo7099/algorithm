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

    string tmp = "";
    bool m = false;
    int ans = 0;

    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
            if (m)
                ans -= stoi(tmp);
            else
                ans += stoi(tmp);

            tmp = "";

            if (s[i] == '-') {
                m = true;
            }

            continue;
        }

        tmp += s[i];
    }

    cout << ans << endl;

    return 0;
}
