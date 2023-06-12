#include <iostream>

using namespace std;

int heap[100002];
int sz = 0;

bool isMin(int a, int b) {
    if (abs(a) < abs(b)) return 1;
    if (abs(a) == abs(b) and a < b) return 1;
    return 0;
}

void push(int x) {
    heap[++sz] = x;
    int idx = sz;

    while (idx != 1) {
        int par = idx / 2;
        if (isMin(heap[par], heap[idx])) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int pop() {
    int ret = heap[1];
    heap[1] = heap[sz--];
    int idx = 1;

    while (idx * 2 <= sz) {
        int lc = 2 * idx, rc = 2 * idx + 1;
        int min_child = lc;
        if (rc <= sz and isMin(heap[rc], heap[lc]))
            min_child = rc;
        if (isMin(heap[idx], heap[min_child])) break;
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

    while (n--) {
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