#include <iostream>

#define ll long long;
using namespace std;

const int MX = 100002;

struct Poketmon {
    int index;
    char name[21];
    Poketmon* nxt;
};

int n, m;
Poketmon hash_tb[MX];  // 포켓몬 -> 숫자
Poketmon pool[MX];
int pcnt;
Poketmon arr[MX];  // 숫자 -> 포켓몬

void mystrcpy(char* dest, const char* src) {
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

int mystrcmp(const char* a, const char* b) {
    while (*a && *a++ == *b++) ++a, ++b;
    return *a - *b;
}

unsigned long long my_hash(const char* str) {
    unsigned long long hash = 5381;
    int c;

    while (c = *str++) {
        hash = (((hash << 5) + hash) + c) % MX;
    }

    return hash % MX;
}

int change(char* str) {
    int i, len;
    int sum, mul;

    sum = 0;
    mul = 1;

    for (i = 0; str[i]; i++) {
    }

    len = i;

    for (i = len - 1; i >= 0; i--) {
        sum += (str[i] - '0') * mul;
        mul *= 10;
    }

    return sum;
}

int main() {
    char str[21];
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> str;

        unsigned long long h = my_hash(str);
        Poketmon* nd = &pool[pcnt++];

        nd->index = i;
        mystrcpy(nd->name, str);

        nd->nxt = hash_tb[h].nxt;
        hash_tb[h].nxt = nd;

        mystrcpy(arr[i].name, str);
    }

    for (int i = 0; i < m; i++) {
        cin >> str;

        if ('0' < str[0] && str[0] <= '9') {
            int index = change(str);
            cout << arr[index].name << '\n';

        } else {
            unsigned long long h = my_hash(str);
            Poketmon* nd = hash_tb[h].nxt;

            while (nd) {
                if (!mystrcmp(nd->name, str)) {
                    cout << nd->index << '\n';
                    break;
                }

                nd = nd->nxt;
            }
        }
    }
    return 0;
}