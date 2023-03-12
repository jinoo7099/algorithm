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

int n = 10;
int arr[10];
int mal[4];
int dist[35];  // 다음 이동할 노드
int turn[35];  // 파란색 지점
int score[35];
bool vis[34];
int ans;

void solve(int cur, int cur_score) {
    if (cur == n) {
        ans = max(ans, cur_score);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int prev = mal[i];
        int now = prev;

        int move = arr[cur];

        if (turn[now] > 0) {
            now = turn[now];
            move -= 1;
        }

        while (move--) {
            now = dist[now];
        }

        if (now != 21 && vis[now] == true) continue;

        vis[prev] = false;
        vis[now] = true;
        mal[i] = now;

        solve(cur + 1, cur_score + score[now]);

        vis[prev] = true;
        vis[now] = false;
        mal[i] = prev;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 21; i++) {
        dist[i] = i + 1;
    }
    dist[21] = 21;

    for (int i = 22; i < 27; i++) dist[i] = i + 1;
    dist[28] = 29;
    dist[29] = 30;
    dist[30] = 25;
    dist[31] = 32;
    dist[32] = 25;
    dist[27] = 20;

    turn[5] = 22;
    turn[10] = 31;
    turn[15] = 28;
    turn[25] = 26;

    for (int i = 0; i < 21; i++) {
        score[i] = i * 2;
    }
    score[22] = 13;
    score[23] = 16;
    score[24] = 19;
    score[31] = 22;
    score[32] = 24;
    score[28] = 28;
    score[29] = 27;
    score[30] = 26;
    score[25] = 25;
    score[26] = 30;
    score[27] = 35;

    solve(0, 0);

    cout << ans << endl;

    return 0;
}
