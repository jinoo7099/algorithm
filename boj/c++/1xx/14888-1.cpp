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

int minx = 1e9, maxx = -1e9;
int n;
int arr[102];
int vis[102];
int op[5];

void solve(int cur, int sum) {
    if (cur == n) {
        minx = min(minx, sum);
        maxx = max(maxx, sum);
        return;
    }

    if (op[0] > 0) {
        op[0]--;
        solve(cur + 1, sum + arr[cur]);
        op[0]++;
    }
    if (op[1] > 0) {
        op[1]--;
        solve(cur + 1, sum - arr[cur]);
        op[1]++;
    }
    if (op[2] > 0) {
        op[2]--;
        solve(cur + 1, sum * arr[cur]);
        op[2]++;
    }
    if (op[3] > 0) {
        op[3]--;
        solve(cur + 1, sum / arr[cur]);
        op[3]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    solve(1, arr[0]);

    cout << maxx << endl
         << minx << endl;
    return 0;
}
