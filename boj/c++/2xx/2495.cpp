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

char s[3][10];
int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%s", &s[i]);
    }

    for (int i = 0; i < 3; i++) {
        int ans = 1;
        int cnt = 1;
        for (int j = 1; j < 8; j++) {
            if (s[i][j] == s[i][j - 1]) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
