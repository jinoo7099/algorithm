#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<int> arr[10000];
vector<int> back[10000];
vector<int> scc[10000];
int vis[10000];
int rev_vis[10000];
int scc_id[10000];
int v, e;
int a, b;

void solve(stack<int>& st, int x) {
    vis[x] = 1;

    for (int i = 0; i < arr[x].size(); i++) {
        if (vis[arr[x][i]])
            continue;
        solve(st, arr[x][i]);
    }

    st.push(x);
}

void revDFS(int x, int id) {
    rev_vis[x] = 1;
    scc[id].push_back(x);
    scc_id[x] = id;

    for (int i = 0; i < back[x].size(); i++) {
        if (rev_vis[back[x][i]]) {
            if (id != scc_id[back[x][i]]) {
                scc[scc_id[back[x][i]]].clear();
            }
            continue;
        }

        revDFS(back[x][i], id);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> v;
        if (v == 0) break;
        cin >> e;

        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            arr[a].push_back(b);
            back[b].push_back(a);
        }

        stack<int> st;
        for (int i = 1; i <= v; i++) {
            if (vis[i]) continue;
            solve(st, i);
        }

        int idx = 0;
        while (!st.empty()) {
            if (rev_vis[st.top()]) {
                st.pop();
                continue;
            }

            revDFS(st.top(), idx);
            idx++;

            st.pop();
        }

        vector<int> res;

        for (int i = 0; i < v; i++) {
            for (auto& s : scc[i]) {
                res.push_back(s);
            }
        }

        sort(res.begin(), res.end());

        for (auto r : res) {
            cout << r << ' ';
        }

        cout << endl;

        for (int i = 0; i < 10000; i++) {
            arr[i].clear();
            back[i].clear();
            scc[i].clear();
        }
        memset(scc_id, 0, sizeof(scc_id));
        memset(vis, 0, sizeof(vis));
        memset(rev_vis, 0, sizeof(rev_vis));
    }
    return 0;
}

/*
    다시 풀기
*/