#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int ch[102];

int main() {
    int n, p;
    scanf("%d %d", &n, &p);

    int tmp = n;
    while (1) {
        int k = tmp * n % p;
        ch[k]++;
        tmp = k;
        if (ch[k] > 2)
            break;
    }

    int ans = 0;

    for (int i = 0; i <= 97; i++) {
        if (ch[i] >= 2)
            ans++;
    }

    printf("%d", ans);

    return 0;
}
