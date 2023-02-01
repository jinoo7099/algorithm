#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

int n = 8;
char d[20][20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    queue<pair<pair<int, int>, int>> q;

    while (q.size()) {
        auto cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur.first == 0 && cur.second == n - 1) {
            cout << 1 << endl;
            return 0;
        }

        if (d[cur.first - cnt][cur.second] == '#') {
            continue;
        }

        for (int i = 0; i < 8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (d[nx][ny] == '#') continue;

            q.push({{nx, ny}, cnt + 1});
        }
    }

    cout << 0 << endl;
    return 0;
}
