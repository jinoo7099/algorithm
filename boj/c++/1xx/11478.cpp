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

    unordered_set<string> st;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            string new_str = s.substr(i, j);
            st.insert(new_str);
        }
    }

    cout << st.size() << endl;

    return 0;
}
