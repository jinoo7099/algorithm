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

int maxx = -2e9;
int minx = 2e9;

void solve(int cur, vector<int> a, vector<int> o, int sum) {
    if (cur == a.size()) {
        maxx = max(sum, maxx);
        minx = min(sum, minx);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (o[i]) {
            if (i == 0) {
                o[i] -= 1;
                solve(cur + 1, a, o, sum + a[cur]);
                o[i] += 1;
            } else if (i == 1) {
                o[i] -= 1;
                solve(cur + 1, a, o, sum - a[cur]);
                o[i] += 1;
            } else if (i == 2) {
                o[i] -= 1;
                solve(cur + 1, a, o, sum * a[cur]);
                o[i] += 1;
            } else {
                o[i] -= 1;
                solve(cur + 1, a, o, sum / a[cur]);
                o[i] += 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> o(4);
    for (int i = 0; i < 4; i++) {
        cin >> o[i];
    }

    solve(1, a, o, a[0]);

    cout << maxx << endl
         << minx << endl;

    return 0;
}
