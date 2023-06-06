#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;
const int nax = 1e5 + 5;

int v, e;
vector<pair<int, int>> adj[nax];
bool ch[nax];

void solve() {
    int cnt = 0;
    priority_queue<tuple<int, int, int>,
                   vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;

    ch[1] = 1;
    for (auto nxt : adj[1])
        pq.push({nxt.first, 1, nxt.second});

    while (cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();

        if (ch[b]) continue;
        cout << cost << ' ' << a << ' ' << b << endl;
        ch[b] = 1;
        cnt++;

        for (auto nxt : adj[b]) {
            if (!ch[nxt.second])
                pq.push({nxt.first, b, nxt.second});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
