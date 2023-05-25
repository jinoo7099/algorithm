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

int ch[10002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r;
    cin >> n >> r;

    for (int i = 0; i < r; i++) {
        int k;
        cin >> k;
        ch[k] = 1;
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!ch[i]) ans.push_back(i);
    }

    if (ans.size() == 0)
        cout << '*' << endl;
    else
        for (auto x : ans)
            cout << x << ' ';

    return 0;
}
