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
char d[52][52];
int vis[52][52];

void go(int cur, int x1, int y1, int x2, int y2) {
    queue<pair<int, int>> q;
    q.push({x1, y1});
    q.push({x2, y2});
    vis[x1][y1] = 1;
    vis[x2][y2] = 1;
    int cnt = 0;

    while (q.size()) {
        cnt++;
        auto n1 = q.front();
        q.pop();
        auto n2 = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int flag1 = false;
            int flag2 = false;

            if (i == 0) {
                for (int j = n1.first; j >= 0; j--) {
                    if (d[j][y1] == '.') {
                        n1.first = j;
                    } else if (d[j][y1] == 'O') {
                        flag1 = true;
                        n1.first = j;
                    }
                }
                for (int j = n2.first; j >= 0; j--) {
                    if (d[j][y2] == '.') {
                        n2.first = j;
                    } else if (d[j][y2] == 'O') {
                        flag2 = true;
                        n2.first = j;
                    }
                }
            } else if (i == 1) {
            } else if (i == 2) {
            } else {
            }

            cout << n1.first << " " << n1.second << endl;
            cout << n2.first << " " << n2.second << endl;

            if (flag1 && flag2) {
                cout << cnt << endl;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int x1, x2, y1, y2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];

            if (d[i][j] == 'R') {
                x1 = i;
                y1 = j;
            } else if (d[i][j] == 'B') {
                x2 = i;
                y2 = j;
            }
        }
    }

    go(0, x1, y1, x2, y2);

    return 0;
}
