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

int n, m;
int adj[202][202];
int plan[1002];
int parent[202];

int findSet(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = findSet(parent[x]);
}

void unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);

    if (x != y) {
        if (x < y)
            parent[y] = x;
        else
            parent[x] = y;
    }
}

bool isSameParent(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    if (x == y)
        return true;
    else
        return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    // make set
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if (adj[i][j]) {
                unionSet(i, j);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> plan[i];
    }

    for (int i = 0; i < m - 1; i++) {
        if (!isSameParent(plan[i], plan[i + 1])) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
