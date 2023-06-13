#include <iostream>

using namespace std;

int n, m, ans;

struct Node {
    int node;
    Node* nxt;
};

Node head[110];
Node pool[110 * 100];
int pcnt;

void insert(int a, int b) {
    Node* nd = &pool[pcnt++];
    nd->node = b;

    nd->nxt = head[a].nxt;
    head[a].nxt = nd;
}

int q[110 * 100];
int front, rear;
int vis[110];

void bfs() {
    int cur;

    q[rear++] = 1;
    vis[1] = 1;

    while (front < rear) {
        cur = q[front++];

        for (Node* p = head[cur].nxt; p; p = p->nxt) {
            if (vis[p->node]) continue;

            vis[p->node] = 1;
            ans++;
            q[rear++] = p->node;
        }
    }
}

void test() {
    for (int i = 1; i <= n; i++) {
        cout << "#" << i << ' ';
        for (Node* p = head[i].nxt; p; p = p->nxt) {
            cout << p->node << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        insert(a, b);
        insert(b, a);
    }

    // test();

    bfs();

    cout << ans << endl;

    return 0;
}
