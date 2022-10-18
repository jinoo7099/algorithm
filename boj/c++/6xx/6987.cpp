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

int arr[6][3];
int dist[6][3];
int vis[6];
int ans;
vector<pair<int, int>> teams;
void solve(int cur) {
    if (cur == 15) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] != dist[i][j])
                    return;
            }
        }
        ans = 1;
        return;
    }

    int t1 = teams[cur].first;
    int t2 = teams[cur].second;

    dist[t1][0]++;
    dist[t2][2]++;
    solve(cur + 1);
    dist[t1][0]--;
    dist[t2][2]--;

    dist[t1][2]++;
    dist[t2][0]++;
    solve(cur + 1);
    dist[t1][2]--;
    dist[t2][0]--;

    dist[t1][1]++;
    dist[t2][1]++;
    solve(cur + 1);
    dist[t1][1]--;
    dist[t2][1]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            teams.push_back({i, j});
        }
    }

    for (int i = 0; i < 4; i++) {
        ans = 0;

        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> arr[j][k];
                dist[j][k] = 0;
            }
        }

        solve(0);

        cout << ans << ' ';
    }

    return 0;
}
