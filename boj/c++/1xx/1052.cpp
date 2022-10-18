#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, k, res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<>> pq;

    cin >> n >> k;

    if (n <= k) {
        cout << 0 << endl;
        return 0;
    }

    while (1) {
        int cnt = 0;
        int tmp_n = n;

        while (tmp_n) {
            if (tmp_n % 2) {
                cnt++;
            }
            tmp_n /= 2;
        }

        if (cnt <= k) {
            cout << res << endl;
            return 0;
        }

        n++;
        res++;
    }

    return 0;
}
