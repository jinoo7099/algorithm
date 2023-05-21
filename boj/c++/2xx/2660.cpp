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

vector<int> adj[52];
int dist[52];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (1) {
        int a, b;
        cin >> a >> b;

        if (a == -1 && b == -1) break;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int, int>> friends;  // 점수, 후보 인덱스

    for (int i = 1; i <= n; i++) {
        fill(dist, dist + 50, -1);

        queue<int> q;
        q.push(i);
        dist[i] = 0;

        while (q.size()) {
            int cur = q.front();
            q.pop();

            for (auto nxt : adj[cur]) {
                if (dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }

        int cnt = *max_element(dist, dist + 50);
        friends.push_back({cnt, i});
    }

    sort(friends.begin(), friends.end());

    int minx = friends[0].first;

    vector<int> res;
    for (int i = 0; i < friends.size(); i++) {
        if (friends[i].first == minx) {
            res.push_back(friends[i].second);
        }
    }

    cout << minx << ' ' << res.size() << endl;
    for (auto a : res) {
        cout << a << ' ';
    }

    return 0;
}
