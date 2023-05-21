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

string arr[1002];

int vis[1002][1002];
bool finished[1002][1002];
int cycle;

void dfs(int x, int y) {
    vis[x][y] = 1;

    if (arr[x][y] == 'U') {
        if (!vis[x - 1][y]) {
            dfs(x - 1, y);
        } else if (vis[x - 1][y] == 1 && !finished[x - 1][y]) {
            ++cycle;
        }
    } else if (arr[x][y] == 'D') {
        if (!vis[x + 1][y]) {
            dfs(x + 1, y);
        } else if (vis[x + 1][y] == 1 && !finished[x + 1][y]) {
            ++cycle;
        }
    } else if (arr[x][y] == 'L') {
        if (!vis[x][y - 1]) {
            dfs(x, y - 1);
        } else if (vis[x][y - 1] == 1 && !finished[x][y - 1]) {
            ++cycle;
        }
    } else if (arr[x][y] == 'R') {
        if (!vis[x][y + 1]) {
            dfs(x, y + 1);
        } else if (vis[x][y + 1] == 1 && !finished[x][y + 1]) {
            ++cycle;
        }
    }

    finished[x][y] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (finished[i][j] == false) {
                dfs(i, j);
            }
        }
    }

    cout << cycle << endl;
    return 0;
}
