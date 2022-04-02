/*
    map 대신 set이 더 깔끔할듯..
*/

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

    int n;
    map<string, bool> mp;
    cin >> n;
    while (n--) {
        string name, state;

        cin >> name >> state;

        if (state == "enter") {
            mp[name] = true;
        } else if (state == "leave") {
            mp[name] = false;
        }
    }
    stack<string> ans;
    for (auto s : mp) {
        if (s.second == true)
            ans.push(s.first);
    }
    while (!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}
