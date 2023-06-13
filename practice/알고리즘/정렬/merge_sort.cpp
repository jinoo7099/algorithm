#include <iostream>

using namespace std;

void mystrcpy(char* a, const char* b) {
    int i = 0;
    while (b[i]) {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';
}

int mystrcmp(const char* a, const char* b) {
    while (*a && *a == *b) ++a, ++b;
    return *a - *b;
}

const int MX = 1000007;
const int a = 1000;

int head[MX];
int pre[MX];
int nxt[MX];
char key[MX][12];
int val[MX];

int unused = 1;

unsigned long my_hash(char* str) {
    unsigned long h = 5381;
    int c;

    while (*str) {
        c = *str;
        h = (((h << 5) + h) + c) % MX;
        str++;
    }

    return h;
}

int find(char* x) {
    unsigned long h = my_hash(x);
    int idx = head[h];

    while (idx != -1) {
        if (mystrcmp(key[idx], x) == 0) return idx;
        idx = nxt[idx];
    }

    return -1;
}

void insert(char* x) {
    int idx = find(x);

    if (idx != -1) {
        return;
    }

    unsigned long h = my_hash(x);
    mystrcpy(key[unused], x);
    val[unused] = 1;

    if (head[h] != -1) {
        nxt[unused] = head[h];
        pre[head[h]] = unused;
    }
    head[h] = unused;
    unused++;
}

void erase(char* x) {
    int idx = find(x);
    if (idx == -1) {
        return;
    }

    val[idx] = 0;
    if (pre[idx] != -1) nxt[pre[idx]] = nxt[idx];
    if (nxt[idx] != -1) pre[nxt[idx]] = pre[idx];

    unsigned int h = my_hash(x);
    if (head[h] == idx) head[h] = nxt[idx];
}

char arr[MX][12];
char tmp[MX][12];

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int aidx = st;
    int bidx = mid;

    for (int i = st; i < en; i++) {
        if (aidx == mid) {
            mystrcpy(tmp[i], arr[bidx++]);
        } else if (bidx == en) {
            mystrcpy(tmp[i], arr[aidx++]);
        } else if (mystrcmp(arr[aidx], arr[bidx]) >= 0) {
            mystrcpy(tmp[i], arr[aidx++]);
        } else {
            mystrcpy(tmp[i], arr[bidx++]);
        }
    }

    for (int i = st; i < en; i++) {
        mystrcpy(arr[i], tmp[i]);
    }
}

void merge_sort(int st, int en) {
    if (st + 1 == en) return;
    int mid = (st + en) / 2;

    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 1; i < MX; i++) {
        head[i] = -1;
        pre[i] = -1;
        nxt[i] = -1;
    }

    int n;
    char a[52], b[52];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        if (mystrcmp("enter", b) == 0) {
            insert(a);
        } else {
            erase(a);
        }
    }

    int idx = 0;
    for (int i = 1; i <= unused; i++) {
        if (val[i] != 0) {
            mystrcpy(arr[idx++], key[i]);
        }
    }

    merge_sort(0, idx);

    for (int i = 0; i < idx; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}