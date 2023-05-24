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

int par[52];
int vis[52];
int leafNodeSize[52];
int n;

int countleafNode(int cur) {
    int s = 0;

    bool isLeaf = true;
    for (int i = 0; i < n; i++) {
        if (cur == par[i]) {
            s += countleafNode(i);
            isLeaf = false;
        }
    }

    leafNodeSize[cur] += s + isLeaf;
    return leafNodeSize[cur];
}

void dfs(int cur) {
    par[cur] = -1;

    for (int i = 0; i < n; i++) {
        if (par[i] == cur) {
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int r;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        par[i] = p;
        if (p == -1) {
            r = i;
        }
    }

    int k;
    cin >> k;

    dfs(k);
    countleafNode(r);

    if (r == k)
        cout << 0 << endl;
    else
        cout << leafNodeSize[r] << endl;

    return 0;
}
