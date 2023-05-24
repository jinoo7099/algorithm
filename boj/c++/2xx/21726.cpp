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

map<string, int> id;
string name[1002];
int deg[1002];
vector<int> adj[1002];
vector<int> ch[1002];
int n, m;
int idx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string a;
        cin >> a;
        name[i] = a;
    }
    sort(name + 1, name + n + 1);

    for (int i = 1; i <= n; i++) {
        id[name[i]] = i;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;

        adj[id[b]].push_back(id[a]);
        deg[id[a]]++;
    }

    vector<int> ac;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            ac.push_back(i);
        }
    }

    cout << ac.size() << endl;
    sort(ac.begin(), ac.end());
    for (auto x : ac) {
        cout << name[x] << ' ';
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        for (int c : adj[i]) {
            if (deg[c] - deg[i] == 1) ch[i].push_back(c);
        }
    }

    for (int i = 1; i <= n; i++) {
        int sz = ch[i].size();
        cout << name[i] << ' ' << sz << ' ';
        for (int c : ch[i]) {
            cout << name[c] << ' ';
        }
        cout << endl;
    }
    return 0;
}
