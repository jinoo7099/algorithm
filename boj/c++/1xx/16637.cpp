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

int n;
vector<int> nums;
vector<char> ops;
int ans = -2e9;

int oper(char a, int b, int c) {
    if (a == '+') return b + c;
    if (a == '-') return b - c;
    if (a == '*') return b * c;
    return 0;
}

void solve(int cur, int fi_num) {
    if (cur == nums.size() - 1) {
        ans = max(ans, fi_num);
        return;
    }

    solve(cur + 1, oper(ops[cur], fi_num, nums[cur + 1]));
    if (cur + 1 < n / 2) {
        int tmp = oper(ops[cur + 1], nums[cur + 1], nums[cur + 2]);
        solve(cur + 2, oper(ops[cur], fi_num, tmp));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;

        if (i % 2 == 0) {
            nums.push_back(a - '0');
        } else {
            ops.push_back(a);
        }
    }

    solve(0, nums[0]);

    cout << ans << endl;

    return 0;
}
