#include <iostream>

using namespace std;

void mystrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int mystrcmp(const char* a, const char* b) {
    while (*a && *a == *b) ++a, ++b;
    return *a - *b;
}

struct student {
    int ko;
    int en;
    int ma;
    char name[15];
};

student heap[100002];
int sz = 0;

bool isMin(student& s1, student& s2) {
    if (s1.ko != s2.ko) return s1.ko > s2.ko;
    if (s1.en != s2.en) return s1.en < s2.en;
    if (s1.ma != s2.ma) return s1.ma > s2.ma;
    if (mystrcmp(s1.name, s2.name) < 0) return true;
    return 0;
}

void push(student st) {
    heap[++sz] = st;
    int idx = sz;

    while (idx != 1) {
        int par = idx / 2;
        if (isMin(heap[par], heap[idx])) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

student pop() {
    student ret = heap[1];
    heap[1] = heap[sz--];
    int idx = 1;

    while (2 * idx <= sz) {
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
        char str[15];
        int a, b, c;

        cin >> str >> a >> b >> c;

        student s;
        s.ko = a;
        s.en = b;
        s.ma = c;
        mystrcpy(s.name, str);

        push(s);
    }

    while (sz) {
        student s = pop();
        cout << s.name << '\n';
    }
    return 0;
}