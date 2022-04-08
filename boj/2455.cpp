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

    int a, b;
    cin >> a >> b;

    int ans = b;
    int sum = b;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b;
        sum = sum - a + b;
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
