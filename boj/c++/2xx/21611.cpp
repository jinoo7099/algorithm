#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, m;
int arr[52][52];
bool is_explore = false;
int m1, m2, m3;

void blizard(int d, int s) {
    int x, y;
    x = y = (n + 1) / 2;

    for (int i = 0; i < s; i++) {
        x += dx[d];
        y += dy[d];

        arr[x][y] = 0;
    }
}

void moveBoard() {
    int x, y;
    x = y = (n + 1) / 2;
    int k = 1;
    int nx, ny;
    nx = x;
    ny = y;
    int d1, d2;
    while (1) {
        if (k % 2 == 1) {
            d1 = 2;
            d2 = 1;
        } else {
            d1 = 3;
            d2 = 0;
        }

        for (int i = 1; i <= k; i++) {
            nx += dx[d1];
            ny += dy[d1];
            if (arr[x][y] == 0) {
                swap(arr[nx][ny], arr[x][y]);
            }
            x = nx;
            y = ny;
        }

        if (k == n) break;

        for (int i = 1; i <= k; i++) {
            nx += dx[d2];
            ny += dy[d2];
            if (arr[x][y] == 0) {
                swap(arr[nx][ny], arr[x][y]);
            }
            x = nx;
            y = ny;
        }
        k++;
    }
}

void printBoard() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

vector<int> findExploredMarble() {
    int x, y;
    x = y = (n + 1) / 2;
    int k = 1;
    int d1, d2;
    vector<int> marbles;

    while (1) {
        if (k % 2 == 1) {
            d1 = 2;
            d2 = 1;
        } else {
            d1 = 3;
            d2 = 0;
        }

        for (int i = 1; i <= k; i++) {
            x += dx[d1];
            y += dy[d1];
            if (arr[x][y] != 0) marbles.push_back(arr[x][y]);
        }

        if (k == n) break;

        for (int i = 1; i <= k; i++) {
            x += dx[d2];
            y += dy[d2];
            if (arr[x][y] != 0) marbles.push_back(arr[x][y]);
        }
        k++;
    }

    vector<int> new_marbles;
    int maxx = 0;
    for (int i = 0; i < marbles.size();) {
        int cnt = 1;
        int val = marbles[i];
        for (int j = i + 1; j < marbles.size(); j++) {
            if (marbles[i] != marbles[j]) break;
            cnt++;
        }
        if (cnt >= 4) {
            maxx = max(maxx, cnt);
            i += cnt;
            is_explore = true;
            if (val == 1) {
                m1 += cnt;
            } else if (val == 2) {
                m2 += cnt;
            } else if (val == 3) {
                m3 += cnt;
            }
        } else {
            new_marbles.push_back(marbles[i]);
            i++;
        }
    }

    return new_marbles;
}

void rearrangeMarble(vector<int> marbles) {
    int x, y;
    x = y = (n + 1) / 2;
    int k = 1;
    int d1, d2;

    int idx = 0;
    int tmp[52][52];
    tmp[x][y] = -1;
    memset(tmp, 0, sizeof(tmp));
    while (idx < marbles.size()) {
        if (k % 2 == 1) {
            d1 = 2;
            d2 = 1;
        } else {
            d1 = 3;
            d2 = 0;
        }

        for (int i = 1; i <= k; i++) {
            if (idx >= marbles.size()) break;
            x += dx[d1];
            y += dy[d1];
            tmp[x][y] = marbles[idx++];
        }

        if (k == n) break;

        for (int i = 1; i <= k; i++) {
            if (idx >= marbles.size()) break;
            x += dx[d2];
            y += dy[d2];
            tmp[x][y] = marbles[idx++];
        }
        k++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

vector<int> changeMarble() {
    int x, y;
    x = y = (n + 1) / 2;
    int k = 1;
    int d1, d2;
    vector<int> marbles;

    while (1) {
        if (k % 2 == 1) {
            d1 = 2;
            d2 = 1;
        } else {
            d1 = 3;
            d2 = 0;
        }

        for (int i = 1; i <= k; i++) {
            x += dx[d1];
            y += dy[d1];
            if (arr[x][y] != 0) marbles.push_back(arr[x][y]);
        }

        if (k == n) break;

        for (int i = 1; i <= k; i++) {
            x += dx[d2];
            y += dy[d2];
            if (arr[x][y] != 0) marbles.push_back(arr[x][y]);
        }
        k++;
    }

    vector<int> new_marbles;
    int maxx = 0;
    for (int i = 0; i < marbles.size();) {
        int cnt = 1;
        int val = marbles[i];
        for (int j = i + 1; j < marbles.size(); j++) {
            if (marbles[i] != marbles[j]) break;
            cnt++;
        }
        new_marbles.push_back(cnt);
        new_marbles.push_back(val);

        i += cnt;
    }

    return new_marbles;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        x = y = (n + 1) / 2;
        arr[x][y] = -1;
        int d, s;
        cin >> d >> s;

        d -= 1;

        blizard(d, s);
        for (int i = 0; i < s; i++) {
            moveBoard();
        }

        while (1) {
            is_explore = false;
            vector<int> res = findExploredMarble();
            if (!is_explore) break;
            rearrangeMarble(res);
        }

        vector<int> changedMarble = changeMarble();
        rearrangeMarble(changedMarble);
        // printBoard();
    }

    int ans = m1 + 2 * m2 + 3 * m3;
    cout << ans << endl;
    return 0;
}
