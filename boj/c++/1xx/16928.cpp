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
unordered_map<int, int> hm;
int vis[102];

// 어떤 칸이 사다리나 뱀의 출발지라면,
// 반드시 사다리 또는 뱀을 거쳐서만 이동해야 한다.
// 해당 칸에서는 주사위를 통한 이동을 할 수 없다.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n + m; i++) {
        int a, b;
        cin >> a >> b;
        hm[a] = b;
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = 1;

    while (q.size()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == 100) {
            cout << cnt << endl;
            break;
        }
        for (int i = 1; i <= 6; i++) {
            int nx = cur + i;

            if (nx > 100 || vis[nx]) continue;

            if (hm[nx]) {
                q.push({hm[nx], cnt + 1});
                vis[hm[nx]] = 1;
            } else {
                q.push({nx, cnt + 1});
                vis[nx] = 1;
            }
        }
    }
    return 0;
}
