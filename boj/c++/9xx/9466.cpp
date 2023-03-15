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

int nxtNode[100002];
int vis[100002];
int ch[100002];
int ans = 0;

void dfs(int node) {
    int nxt = nxtNode[node];
    vis[node] = 1;

    if (!vis[nxt])
        dfs(nxt);
    else if (!ch[nxt]) {
        for (int i = nxt; i != node; i = nxtNode[i]) {
            ans++;
        }
        ans++;
    }

    ch[node] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ans = 0;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> nxtNode[i];
        }
        memset(vis, 0, sizeof(vis));
        memset(ch, 0, sizeof(ch));

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i);
        }

        cout << n - ans << endl;
    }

    return 0;
}

/*
https://hyeo-noo.tistory.com/45
*/