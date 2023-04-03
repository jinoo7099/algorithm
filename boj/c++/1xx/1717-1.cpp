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

int n, m;

int getParent(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a != b) {
        if (a < b)
            parent[b] = a;
        else
            parent[a] = b;
    }
}

int findParent(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);

    if (a == b) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 0; i < n + 1; i++) {
        v[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0) {
            unionParent(v, a, b);
        } else {
            int res = findParent(v, a, b);
            if (res == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
