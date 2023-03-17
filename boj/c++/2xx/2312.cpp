#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int cnt[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        memset(cnt, 0, sizeof(cnt));
        int num;
        cin >> num;

        int tmp = num;
        for (int j = 2; j * j <= num; j++) {
            while (tmp % j == 0) {
                cnt[j]++;
                tmp /= j;
            }
        }
        if (tmp != 1) cnt[tmp]++;

        for (int i = 2; i <= num; i++) {
            if (cnt[i] > 0) {
                cout << i << ' ' << cnt[i] << endl;
            }
        }
    }

    return 0;
}
