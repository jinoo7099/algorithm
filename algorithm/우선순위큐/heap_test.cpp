#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0;  // heap에 들어있는 원소의 수

void push(int x) {
    heap[++sz] = x;

    int idx = sz;
    while (idx != 1) {
        int par = idx / 2;
        if (heap[par] <= x) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int top() {
    if (sz == 0) return 0;
    return heap[1];
}

void pop() {
    if (sz == 0) return;
    heap[1] = heap[sz--];

    int idx = 1;
    while (2 * idx <= sz) {
        int lc = 2 * idx;
        int rc = 2 * idx + 1;
        int min_child = lc;
        if (rc <= sz && heap[rc] < heap[lc])
            min_child = rc;
        if (heap[idx] <= heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}

void test() {
    push(10);
    push(2);
    push(5);
    push(9);  // {10, 2, 5, 9}
    // for (int i = 1; i <= sz; i++) cout << heap[i] << " ";
    cout << top() << '\n';  // 2
    pop();                  // {10, 5, 9}
    // for (int i = 1; i <= sz; i++) cout << heap[i] << " ";
    pop();  // {10, 9}
    // for (int i = 1; i <= sz; i++) cout << heap[i] << " ";
    cout << top() << '\n';  // 9
    push(5);
    push(15);               // {10, 9, 5, 15}
    cout << top() << '\n';  // 5
    pop();                  // {10, 9, 15}
    cout << top() << '\n';  // 9
}

int main() {
    // test();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            cout << top() << endl;
            pop();
        } else {
            push(x);
        }
    }
}