#include <algorithm>
#include <iostream>
using namespace std;

int heap[1000003];
int sz = 0;

void push(int x) {
    heap[++sz] = x;
    int idx = sz;

    while (idx != 1) {
        int par = idx / 2;
        if (heap[par] <= heap[idx]) break;
        swap(heap[idx], heap[par]);
        idx = par;
    }
}

int top() {
    return heap[1];
}

void pop() {
    heap[1] = heap[sz--];
    int idx = 1;

    while (idx * 2 <= sz) {
        int lc = idx * 2, rc = idx * 2 + 1;
        int min_child = lc;
        if (rc <= sz and heap[rc] < heap[lc])
            min_child = rc;
        if (heap[idx] < heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}

int main() {
    push(-10);
    push(-2);
    push(-5);
    push(-9);  // {10, 2, 5, 9}

    cout << -top() << '\n';  // 2
    pop();                   // {10, 5, 9}
    pop();                   // {10, 9}
    cout << -top() << '\n';  // 9

    push(-5);
    push(-15);               // {10, 9, 5, 15}
    cout << -top() << '\n';  // 5
    pop();                   // {10, 9, 15}
    cout << -top() << '\n';  // 9
    return 0;
}