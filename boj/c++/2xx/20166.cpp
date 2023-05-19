#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

string arr[12];
unordered_map<string, int> str_cnt;
int n, m, k;

void dfs(int i, int j, string s) {
    str_cnt[s]++;
    if (s.size() == 5) return;

    for (int dir = 0; dir < 8; dir++) {
        int nx = (i + dx[dir] + n) % n;
        int ny = (j + dy[dir] + m) % m;
        dfs(nx, ny, s + arr[nx][ny]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) dfs(i, j, string(1, arr[i][j]));

    while (k--) {
        string s;
        cin >> s;
        cout << str_cnt[s] << endl;
    }

    return 0;
}
