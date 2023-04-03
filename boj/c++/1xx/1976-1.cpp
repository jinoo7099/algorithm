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
int citys[202][202];
int parents[202];

int getParent(int x) {
    if (parents[x] == x)
        return x;
    return parents[x] = getParent(parents[x]);
}

void uninonParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a != b) {
        if (a < b)
            parents[b] = a;
        else
            parents[a] = b;
    }
}

int findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a == b) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> citys[i][j];
            if (citys[i][j] == 1) {
                uninonParent(i, j);
            }
        }
    }
    vector<int> travels(m);
    for (int i = 0; i < m; i++) {
        cin >> travels[i];
    }

    for (int i = 0; i < m - 1; i++) {
        int res = findParent(travels[i], travels[i + 1]);
        if (res == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
