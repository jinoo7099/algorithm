#include <iostream>

using namespace std;

const int M = 2005;
const int a = 100;
const int MX = 1002;

int head[M];
int pre[M];
int nxt[M];

char key[M][22];
int val[M];
int unused = 0;

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

int my_hash(char* k) {
    int h = 0;
    while (*k) {
        h = (h * a + *k) % M;
        k++;
    }
    return h;
}

int find(char* k) {
    int h = my_hash(k);
    int idx = head[h];
    while (idx != -1) {
        if (mystrcmp(key[idx], k) == 0) break;
        idx = nxt[idx];
    }

    return idx;
}

void push(char* k) {
    int idx = find(k);
    // 1증가
    if (idx != -1) {
        val[idx] += 1;
        return;
    }

    // 1 초기화
    int h = my_hash(k);

    mystrcpy(key[unused], k);
    val[unused] = 1;

    if (head[h] != -1) {
        nxt[unused] = head[h];
        pre[head[h]] = unused;
    }
    head[h] = unused;
    unused++;
}

int main() {
    for (int i = 0; i < M; i++) {
        head[i] = -1;
        pre[i] = -1;
        nxt[i] = -1;
    }
    int n;
    cin >> n;

    while (n--) {
        char str[22];
        cin >> str;
        push(str);
    }

    int maxx = -1;
    char ans[22] = "";
    for (int i = 0; i < unused; i++) {
        if (maxx < val[i]) {
            if (mystrcmp(ans, key[i]) < 0) {
                mystrcpy(ans, key[i]);
                maxx = val[i];
            }
        }
    }

    cout << ans << ' ' << maxx << endl;
    return 0;
}