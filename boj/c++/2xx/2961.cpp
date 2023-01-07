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

int s, b;
vector<pair<int, int>> v;
int n, ans = 1e9;

void go(int cur, int s_sum, int b_sum) {
    if (cur == v.size()) {
        if (b_sum)
            ans = min(ans, abs(s_sum - b_sum));
        return;
    }

    // 해당 음식 선택 x
    go(cur + 1, s_sum, b_sum);

    // 해당 음식 선택 o
    go(cur + 1, s_sum * v[cur].first, b_sum + v[cur].second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int ss, bb;

        cin >> ss >> bb;
        v.push_back({ss, bb});
    }

    go(0, 1, 0);

    cout << ans << endl;

    return 0;
}
