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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, l;
    cin >> n >> w >> l;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    deque<int> dq;
    for (int i = 0; i < w; i++) {
        dq.push_back(0);
    }

    int ptr = 0;
    int sum = 0, ret = 0;
    while (ptr < n) {
        sum -= dq.front();
        dq.pop_front();

        if (v[ptr] + sum <= l) {
            dq.push_back(v[ptr]);
            sum += v[ptr];
            ptr++;
        } else {
            dq.push_back(0);
        }
        ret++;
    }

    cout << ret + w << endl;

    return 0;
}
