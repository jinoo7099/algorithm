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
int s[22];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a;

    while (n--) {
        string str;
        cin >> str;
        if (str == "add") {
            cin >> a;
            s[a] = 1;
        } else if (str == "remove") {
            cin >> a;
            s[a] = 0;
        } else if (str == "check") {
            cin >> a;
            cout << (s[a] ? 1 : 0) << endl;
        } else if (str == "toggle") {
            cin >> a;
            s[a] ? s[a] = 0 : s[a] = 1;
        } else if (str == "all") {
            for (int i = 1; i <= 20; i++) {
                s[i] = 1;
            }
        } else if (str == "empty") {
            for (int i = 1; i <= 20; i++) {
                s[i] = 0;
            }
        }
    }
    return 0;
}
