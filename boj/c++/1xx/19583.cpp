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

    string s, e, q;
    cin >> s >> e >> q;

    unordered_map<string, int> stu;
    string h, nickname;
    unordered_set<string> ans;

    while (cin >> h >> nickname) {
        if (h <= s) {
            stu[nickname] = 1;
        } else if (e <= h and h <= q) {
            if (stu[nickname] == 1) {
                ans.insert(nickname);
            }
        }
    }

    cout << ans.size() << endl;
    return 0;
}
