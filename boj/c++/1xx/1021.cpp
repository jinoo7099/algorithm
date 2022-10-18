#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    deque<int> dq;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        cin >> k;

        if (dq.front() == k) {
            dq.pop_front();
            continue;
        }

        int idx = 0;
        for (auto a : dq) {
            if (a == k) {
                break;
            }
            idx++;
        }

        int b = dq.size() - idx;
        if (idx <= b) {
            res += idx;
            while (idx--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            res += b;
            while (b--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        dq.pop_front();
    }
    cout << res << endl;

    return 0;
}
