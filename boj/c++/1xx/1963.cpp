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

bool d[10002];
int vis[10002];

void getPrimeNumber() {
    for (int i = 2; i <= 10000; i++) {
        d[i] = 1;
    }

    for (int i = 2; i <= 10000; i++) {
        if (d[i] == 0) continue;

        for (int j = i + i; j <= 10000; j += i) {
            d[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    getPrimeNumber();

    int t;
    cin >> t;

    while (t--) {
        memset(vis, 0, sizeof(vis));
        int a, b;
        cin >> a >> b;

        queue<int> q;
        q.push(a);
        vis[a] = 1;
        bool flag = true;

        while (q.size()) {
            int cur = q.front();
            q.pop();
            int k;

            if (cur == b) {
                cout << vis[cur] - 1 << endl;
                flag = false;
                break;
            }

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j <= 9; j++) {
                    int t = 1000 / pow(10, i);
                    k = cur - cur / t % 10 * t + t * j;
                    if (k < 1000 || k > 9999) continue;
                    if (vis[k]) continue;

                    if (d[k]) {
                        q.push(k);
                        vis[k] = vis[cur] + 1;
                    }
                }
            }
        }

        if (flag) {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
