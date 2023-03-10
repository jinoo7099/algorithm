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

int n, ans;
bool blue[5][10];
bool green[10][5];
/*
    1. n개 만큼 명령
    2. 각 명령마다 블루, 그린에 블록을 쌓아야됨
        2.1 블록의 연한 부분에 있을 시 연할 블록 수 만큼 땅기기
        2.2 블록이 테트리스를 만족할 시 해당 줄을 없애고, 그 수 만큼 땅기기
            -> 점수 계산
        2.3 줄 땅기기로 테트리스가 발생하는 경우는 없음
    3. 얻은 점수 + 블루, 그린 타일 수
*/

void moveRow(int st) {
    for (int i = st; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            green[i][j] = green[i - 1][j];
        }
    }
}

void moveCol(int st) {
    for (int i = st; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            blue[j][i] = blue[j][i - 1];
        }
    }
}

void solve(int t, int x, int y) {
    int b_x, g_x, b_y, g_y;
    // 블록 위치 찾기
    if (t == 1) {
        // green
        g_y = y;
        for (int i = 0; i <= 5; i++) {
            if (green[i][g_y] == true) break;
            g_x = i;
        }
        // blue
        b_x = x;
        for (int i = 0; i <= 5; i++) {
            if (blue[b_x][i] == true) break;
            b_y = i;
        }
    } else if (t == 2) {
        // 1 * 2
        // green
        g_y = y;
        for (int i = 0; i <= 5; i++) {
            if (green[i][g_y] == true || green[i][g_y + 1]) break;
            g_x = i;
        }
        // blue
        b_x = x;
        for (int i = 0; i < 5; i++) {
            if (blue[b_x][i + 1] == true || blue[b_x][i]) break;
            b_y = i;
        }
    } else {
        // 2 * 1
        // green
        g_y = y;
        for (int i = 0; i < 5; i++) {
            if (green[i + 1][g_y] == true || green[i][g_y]) break;
            g_x = i;
        }
        // blue
        b_x = x;
        for (int i = 0; i <= 5; i++) {
            if (blue[b_x][i] == true || blue[b_x + 1][i] == true) break;
            b_y = i;
        }
    }

    // 블록 두기
    green[g_x][g_y] = true;
    blue[b_x][b_y] = true;
    if (t == 2) {
        green[g_x][g_y + 1] = true;
        blue[b_x][b_y + 1] = true;
    } else if (t == 3) {
        green[g_x + 1][g_y] = true;
        blue[b_x + 1][b_y] = true;
    }
    // cout << " GREEN " << endl;
    // for (int i = 0; i <= 5; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << green[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << " blue " << endl;
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j <= 5; j++) {
    //         cout << blue[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // 테트리스 검사
    // green
    for (int i = 0; i <= 5; i++) {
        bool flag = true;
        for (int j = 0; j < 4; j++) {
            if (green[i][j] == false) {
                flag = false;
                break;
            }
        }
        if (flag) {
            moveRow(i);
            ans++;
        }
    }

    // blue
    for (int i = 0; i <= 5; i++) {
        bool flag = true;
        for (int j = 0; j < 4; j++) {
            if (blue[j][i] == false) {
                flag = false;
                break;
            }
        }
        if (flag) {
            moveCol(i);
            ans++;
        }
    }

    // 연한 부분 검사
    // green
    int g_cnt = 0;
    for (int i = 0; i <= 1; i++) {
        bool flag = true;
        for (int j = 0; j < 4; j++) {
            if (green[i][j] == true) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            g_cnt++;
        }
    }
    for (int i = 0; i < g_cnt; i++) {
        moveRow(5);
    }

    // blue
    int b_cnt = 0;
    for (int i = 0; i <= 1; i++) {
        bool flag = true;
        for (int j = 0; j < 4; j++) {
            if (blue[j][i] == true) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            b_cnt++;
        }
    }
    for (int i = 0; i < b_cnt; i++) {
        moveCol(5);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        solve(t, x, y);
    }

    int total_block_cnt = 0;

    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (green[i][j]) {
                total_block_cnt++;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= 5; j++) {
            if (blue[i][j]) {
                total_block_cnt++;
            }
        }
    }
    cout << ans << endl;
    cout << total_block_cnt << endl;
    return 0;
}

/*
https://www.acmicpc.net/source/56049324
*/