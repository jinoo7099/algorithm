#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, t;
string s1, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s1 >> s2;
    cin >> t;
    reverse(s1.begin(), s1.end());
    string res = s1 + s2;

    while (t--) {
        for (int i = 0; i < n + m - 1; i++) {
            if (s1.find(res[i]) != string::npos && s2.find(res[i + 1]) != string::npos) {
                swap(res[i], res[i + 1]);
                i++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
