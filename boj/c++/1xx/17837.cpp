#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int n, k;
int arr[22][22];
int color[22][22];
int t = 1;

vector<int> order[22][22];  // 말 번호, 방향
map<int, pair<int, pair<int, int>>> horses;

void white(int r, int c, int nx, int ny, int i) {
    bool flag = false;
    vector<int> tmp;
    for (int j = 0; j < order[r][c].size(); j++) {
        if (order[r][c][j] == i) {
            flag = true;
        }
        if (flag) {
            tmp.push_back(order[r][c][j]);
        }
    }
    for (int j = 0; j < tmp.size(); j++) {
        order[r][c].pop_back();

        horses[tmp[j]].second = {nx, ny};
        order[nx][ny].push_back(tmp[j]);
    }
}

void red(int r, int c, int nx, int ny, int i) {
    bool flag = false;
    vector<int> tmp;

    for (int j = 0; j < order[r][c].size(); j++) {
        if (order[r][c][j] == i) {
            flag = true;
        }
        if (flag) {
            tmp.push_back(order[r][c][j]);
        }
    }

    for (int j = tmp.size() - 1; j >= 0; j--) {
        order[r][c].pop_back();

        horses[tmp[j]].second = {nx, ny};
        order[nx][ny].push_back(tmp[j]);
    }
}

void solve() {
    while (t <= 1000) {
        for (int i = 1; i <= k; i++) {
            auto horse = horses[i];
            int d = horse.first;
            int r = horse.second.first;
            int c = horse.second.second;

            int nx = r + dx[d];
            int ny = c + dy[d];

            // 0 white, 1 red, 2 blue
            if (color[nx][ny] == 2 || (nx < 1 || nx > n || ny < 1 || ny > n)) {
                if (d == 0) {
                    d = 1;
                } else if (d == 1) {
                    d = 0;
                } else if (d == 2) {
                    d = 3;
                } else {
                    d = 2;
                }

                nx = r + dx[d];
                ny = c + dy[d];
                horses[i].first = d;

                if (color[nx][ny] == 2 || nx < 1 || nx > n || ny < 1 || ny > n) continue;
            }
            if (color[nx][ny] == 0) {
                white(r, c, nx, ny, i);
            } else if (color[nx][ny] == 1) {
                red(r, c, nx, ny, i);
            }

            if (order[nx][ny].size() >= 4) {
                return;
            }
        }
        t++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> color[i][j];
        }
    }

    for (int i = 1; i <= k; i++) {
        int r, c, d;
        cin >> r >> c >> d;

        order[r][c].push_back(i);
        horses[i] = {d - 1, {r, c}};
    }

    solve();

    if (t > 1000) {
        cout << -1 << endl;
    } else {
        cout << t << endl;
    }
    return 0;
}
