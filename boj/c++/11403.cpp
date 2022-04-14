/*
    경로 찾기
        플로이드 와샬
*/

#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;
int arr[102][102];
int res[102][102];
int vis[102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) arr[i][j] = 1e9;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1e9) {
                cout << 0 << ' ';
            } else {
                cout << 1 << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}

/*
#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;
int arr[102][102];
int res[102][102];
int vis[102];

void dfs(int x, int st) {
    vis[x] = 1;

    for (int i = 0; i < n; i++) {
        if (!arr[x][i]) continue;
        if (vis[i] == 1 && i == st) {
            res[st][i] = 1;
        }
        if (vis[i]) continue;
        res[st][i] = 1;
        dfs(i, st);
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
        fill(vis, vis + 102, 0);
        dfs(i, i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

*/