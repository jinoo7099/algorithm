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
int parent[1000002];

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

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    while (m--) {
        int k, a, b;
        cin >> k >> a >> b;

        if (!k) {
            unionSet(a, b);
        } else {
            if (isSameParent(a, b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
