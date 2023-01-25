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

bool check[1502][1502];
int sum;
void dfs(int x, int y) {
    if (check[x][y]) return;
    check[x][y] = true;
    int a[3] = {x, y, sum - x - y};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i] < a[j]) {
                int b[3] = {x, y, sum - x - y};
                b[i] += a[i];
                b[j] -= a[i];
                dfs(b[0], b[1]);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    sum = a + b + c;
    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    dfs(a, b);

    if (check[sum / 3][sum / 3]) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
