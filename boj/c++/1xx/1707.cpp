#include <iostream>

using namespace std;

struct Node {
    int node;
    Node *nxt;
};

int k, v, e;

Node head[20200];
Node pool[200200 * 2];
int vis[20200];
int pcnt;

void init() {
    pcnt = 0;

    for (int i = 1; i <= v; i++) {
        head[i].nxt = 0;
        vis[i] = 0;
    }
}

void insert(int p, int c) {
    Node *nd = &pool[pcnt++];
    nd->node = c;

    nd->nxt = head[p].nxt;
    head[p].nxt = nd;
}

int dfs(int node, int color) {
    vis[node] = color;

    for (Node *p = head[node].nxt; p; p = p->nxt) {
        // if (vis[p->node] == color) return 0;
        // if (!vis[p->node]) {
        // if (!dfs(p->node, 3 - color)) return 0;
        // }

        if (vis[p->node] == color) return 0;
        if (!vis[p->node]) {
            /* 3 - 1 = 2 <-> 3 - 2 = 1 */
            if (!dfs(p->node, 3 - color)) return 0;
        }
    }

    return 1;
}

void test() {
    for (int i = 1; i <= v; i++) {
        cout << "#" << i << ' ';
        for (Node *p = head[i].nxt; p; p = p->nxt) {
            cout << p->node << ' ';
        }
        cout << endl;
    }
}

void solve() {
    cin >> v >> e;

    init();

    for (int i = 0; i < e; i++) {
        int p, c;
        cin >> p >> c;

        insert(p, c);
        insert(c, p);
    }

    // test();
    int flag = 0;
    for (int i = 1; i <= v; i++) {
        if (vis[i]) continue;

        flag = dfs(i, 1);
        if (!flag) break;
    }

    if (flag)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main() {
    cin >> k;
    while (k--) solve();
    return 0;
}