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

int n, r, c;

int solve(int n, int r, int c) {
    if (n == 0) {
        return 0;
    }

    int half = 1 << (n - 1);

    if (r < half && c < half)
        return solve(n - 1, r, c);
    else if (r < half && c >= half)
        return solve(n - 1, r, c - half) + half * half;
    else if (r >= half && c < half)
        return solve(n - 1, r - half, c) + half * half * 2;
    else if (r >= half && c >= half)
        return solve(n - 1, r - half, c - half) + half * half * 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;

    cout << solve((2 << n), r, c);

    return 0;
}
