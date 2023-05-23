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

vector<int> adj[1002];

int vis[1002];
bool finished[1002];
int node_order;
int cycle;

void dfs(int node) {
    vis[node] = node_order++;  // node 번호

    for (auto nxt : adj[node]) {
        if (vis[nxt] == -1) {
            dfs(nxt);
        } else if (!finished[node]) {
            ++cycle;
        }
    }

    finished[node] = true;
}

// int ans;
// int vis[502];
// bool isTree = true;
// vector<int> adj[502];
// void dfs_by_undirected_graph(int x, int par) {
//     for (auto nxt : adj[x]) {
//         if (nxt == par)
//             continue;
//         if (vis[nxt]) {
//             isTree = false;
//             continue;
//         }

//         vis[nxt] = 1;
//         dfs(nxt, x);
//     }
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dfs(1);

    cout << cycle << endl;
    return 0;
}

/*
    // https://nicotina04.tistory.com/148
    vis와 finished 배열을 이용해 dfs를 돌려 사이클 판단

    1 -> 2 -> 3 -> 1로 정점이 연결되어 있을 때

    1, 2, 3 vis == true로 바꾸고 다시 1로 방문할 때
    1이 finished가 false면 사이클이 발생함

    //

    node order를 추가하면 사이클 내에 노드 개수를 셀 수 있다.
*/