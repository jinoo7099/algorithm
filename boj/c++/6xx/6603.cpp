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
vector<int> lotto;
void solve(int cur, int s, vector<int> a) {
    if (cur == 6) {
        for (auto r : lotto) {
            cout << r << ' ';
        }
        cout << endl;
        return;
    }

    int n = a.size();
    for (int i = s; i < n; i++) {
        lotto.push_back(a[i]);
        solve(cur + 1, i + 1, a);
        lotto.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        solve(0, 0, a);
        cout << endl;
    }

    return 0;
}
