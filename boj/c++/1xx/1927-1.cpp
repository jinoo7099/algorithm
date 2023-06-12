#include <iostream>

using namespace std;

const int MX = 100002;
int heap[MX];
int sz = 0;

void push(int x) {
    heap[++sz] = x;
    int idx = sz;

    while (idx != 1) {
        int par = idx / 2;
        if (heap[par] <= heap[idx]) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int pop() {
    int ret = heap[1];
    heap[1] = heap[sz--];
    int idx = 1;

    while (2 * idx <= sz) {
        int lc = 2 * idx, rc = 2 * idx + 1;
        int min_child = lc;
        if (rc <= sz and heap[rc] < heap[lc])
            min_child = rc;
        if (heap[idx] <= heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            if (sz == 0)
                cout << 0 << '\n';
            else
                cout << pop() << '\n';
        } else {
            push(x);
        }
    }
    return 0;
}