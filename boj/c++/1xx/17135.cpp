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

int n, m, d;
int arr[22][22];
int ch[22][22];
int ans;
int sum;
bool isEnd;

int getDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void attack(vector<int> arrowers) {
    memset(ch, 0, sizeof(ch));
    for (int i = 0; i < arrowers.size(); i++) {
        if (arrowers[i] == 1) {
            int p_x = n + 1;
            int p_y = i + 1;

            bool flag = false;
            vector<pair<int, pair<int, int>>> enemys;

            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= m; y++) {
                    if (arr[x][y] == 1) {
                        int dis = getDistance(p_x, p_y, x, y);

                        if (dis <= d) {
                            enemys.push_back({dis, {y, x}});
                        }
                    }
                }
            }

            if (enemys.size()) {
                sort(enemys.begin(), enemys.end());
                ch[enemys[0].second.second][enemys[0].second.first] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ch[i][j] == 1) {
                sum++;
                arr[i][j] = 0;
            }
        }
    }
}

void move() {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = arr[i - 1][j];
        }
    }
}

void check() {
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 1) {
                flag = true;
            }
        }
    }

    if (!flag) {
        isEnd = true;
    }
}

void solve(vector<int> arrowers) {
    sum = 0;
    isEnd = false;

    while (1) {
        attack(arrowers);
        move();
        check();

        if (isEnd) {
            break;
        }
    }

    ans = max(ans, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> d;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> arrowers;
    for (int i = 0; i < m; i++) {
        if (i >= m - 3) {
            arrowers.push_back(1);
        } else {
            arrowers.push_back(0);
        }
    }

    int tmp[22][22];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            tmp[i][j] = arr[i][j];

    do {
        solve(arrowers);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                arr[i][j] = tmp[i][j];
    } while (next_permutation(arrowers.begin(), arrowers.end()));

    cout << ans << endl;

    return 0;
}
