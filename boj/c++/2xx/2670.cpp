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

double arr[10001];
double dp[10001];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    double maxx = -1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] * arr[i], arr[i]);
        maxx = max(dp[i], maxx);
    }

    printf("%.3f", maxx);
    // cout << maxx << endl;
    return 0;
}
