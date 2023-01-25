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

int vis[10002];

string padStart(string s) {
    int K = 4;
    string newString = "";
    for (int i = 0; i < K - s.size(); i++) {
        newString += "0";
    }
    newString += s;
    return newString;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        memset(vis, 0, sizeof(vis));
        int a, b;
        cin >> a >> b;

        queue<pair<int, string>> q;
        q.push({a, ""});
        vis[a] = 1;

        while (q.size()) {
            auto cur = q.front();
            int nx = cur.first;
            string cnt = cur.second;
            if (nx == b) {
                cout << cnt << endl;
                break;
            }
            q.pop();

            for (int d = 0; d < 4; d++) {
                int k;
                if (d == 0) {
                    k = 2 * nx % 10000;
                    if (vis[k]) continue;
                    // 0
                    q.push({k, cnt + 'D'});
                    vis[k] = 1;
                }

                if (d == 1) {
                    int k = (nx == 0 ? 9999 : nx - 1);
                    if (vis[k]) continue;
                    // 1
                    q.push({k, cnt + 'S'});
                    vis[k] = 1;
                }

                if (d == 2) {
                    // 2
                    // string s = padStart(to_string(nx));
                    k = nx * 10 + nx / 1000 - nx / 1000 * 10000;
                    if (vis[k]) continue;
                    q.push({k, cnt + 'L'});
                    vis[k] = 1;
                }

                if (d == 3) {
                    // 3
                    // string s = padStart(to_string(nx));
                    k = nx / 10 + nx % 10 * 1000;
                    if (vis[k]) continue;
                    q.push({k, cnt + 'R'});
                    vis[k] = 1;
                }
            }
        }
    }

    return 0;
}
