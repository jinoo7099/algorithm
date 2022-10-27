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

int k[22][22];

int calc(vector<int> d) {
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < d.size(); i++) {
        if (d[i] == 0)
            a.push_back(i);
        else
            b.push_back(i);
    }
    int a_total = 0;
    int b_total = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            a_total += k[a[i]][a[j]] + k[a[j]][a[i]];
            b_total += k[b[i]][b[j]] + k[b[j]][b[i]];
        }
    }

    return abs(a_total - b_total);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> k[i][j];
        }
    }

    vector<int> d;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            d.push_back(0);
        } else {
            d.push_back(1);
        }
    }

    int ans = 1e9;
    do {
        int now = calc(d);
        ans = min(ans, now);
    } while (next_permutation(d.begin(), d.end()));

    cout << ans << endl;

    return 0;
}
