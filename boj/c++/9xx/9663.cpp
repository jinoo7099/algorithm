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
int vis1[52];  // / 대각선
int vis2[52];  // 세로
int vis3[52];  // \ 대각선
int n, ans;

void go(int x) {
    if (x == n) {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (vis1[x + i] || vis2[i] || vis3[x - i + n - 1]) continue;
        vis1[x + i] = 1;
        vis2[i] = 1;
        vis3[x - i + n - 1] = 1;
        go(x + 1);
        vis1[x + i] = 0;
        vis2[i] = 0;
        vis3[x - i + n - 1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    go(0);

    cout << ans << endl;

    return 0;
}
