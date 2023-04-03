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
const int LIMIT = 5;

int n;

vector<int> gen(int k) {
    vector<int> ret(LIMIT);
    for (int i = 0; i < LIMIT; i++) {
        ret[i] = k % 4;
        k /= 4;
    }
    return ret;
}

void up(vector<vector<int>>& a) {
    for (int j = 0; j < n; j++) {
        vector<int> els;
        for (int i = 0; i < n; i++) {
            if (a[i][j] > 0) els.push_back(a[i][j]);
            a[i][j] = 0;
        }
        // 합치기
        vector<int> new_els;
        int l = els.size();
        for (int i = 0; i < l; i++) {
            if (i == l - 1) {
                new_els.push_back(els[i]);
            } else if (els[i] == els[i + 1]) {
                new_els.push_back(2 * els[i]);
                i++;
            } else {
                new_els.push_back(els[i]);
            }
        }

        // 붙이기
        for (int i = 0; i < new_els.size(); i++) {
            a[i][j] = new_els[i];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void rotateToClockwise(vector<vector<int>>& a) {
    vector<vector<int>> tmp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = a[n - j - 1][i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = tmp[i][j];
        }
    }
}

void rotateToCounterClockwise(vector<vector<int>>& a) {
    vector<vector<int>> tmp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = a[j][n - 1 - i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = tmp[i][j];
        }
    }
}

int check(vector<vector<int>> a, vector<int>& dir) {
    int res = 0;
    for (int k : dir) {
        if (k == 0) {
            up(a);
        } else if (k == 1) {
            rotateToCounterClockwise(a);

            up(a);

            rotateToClockwise(a);

        } else if (k == 2) {
            rotateToCounterClockwise(a);
            rotateToCounterClockwise(a);
            up(a);
            rotateToClockwise(a);
            rotateToClockwise(a);
        } else if (k == 3) {
            rotateToClockwise(a);
            up(a);
            rotateToCounterClockwise(a);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, a[i][j]);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = -1;

    for (int i = 0; i < (1 << LIMIT * 2); i++) {
        vector<int> dir = gen(i);

        int res = check(a, dir);
        ans = max(ans, res);
    }

    cout << ans << endl;

    return 0;
}
