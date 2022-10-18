#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;
int vis[20];
int arr[20][20];
int res = 1e9;

void solve(int cur, int sum, int st, int pre) {
    if (cur == n - 1 && arr[pre][st]) {
        res = min(res, sum + arr[pre][st]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i] && arr[pre][i] != 0) {
            vis[i] = 1;
            solve(cur + 1, sum + arr[pre][i], st, i);
            vis[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            solve(0, 0, i, i);
            vis[i] = 0;
        }
    }

    cout << res << endl;

    return 0;
}
