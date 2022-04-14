#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int v, e;

vector<int> arr[10001];

vector<int> back[10001];
int vis[10001];
stack<int> st;

void solve(int x) {
    if (vis[x]) {
        return;
    }

    vis[x] = 1;

    for (int i = 0; i < arr[x].size(); i++) {
        back[arr[x][i]].push_back(x);
        solve(arr[x][i]);
    }

    st.push(x);
}

void solve2(int x, vector<int>& v) {
    if (vis[x]) {
        return;
    }

    vis[x] = 1;
    v.push_back(x);

    for (int i = 0; i < back[x].size(); i++) {
        solve2(back[x][i], v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;

        arr[a].push_back(b);
    }
    for (int i = 1; i <= v; i++) {
        if (!vis[i])
            solve(i);
    }
    memset(vis, 0, sizeof(vis));

    vector<vector<int>> res;

    while (!st.empty()) {
        if (vis[st.top()]) {
            st.pop();
            continue;
        }

        vector<int> v;

        solve2(st.top(), v);

        sort(v.begin(), v.end());
        res.push_back(v);

        st.pop();
    }

    sort(res.begin(), res.end());

    for (auto& a : res) {
        a.push_back(-1);
    }

    cout << res.size() << endl;

    for (auto a : res) {
        for (auto b : a) {
            cout << b << ' ';
        }
        cout << endl;
    }

    return 0;
}
