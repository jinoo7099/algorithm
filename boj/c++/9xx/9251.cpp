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

int dp[1002][1002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            if (str1[i] == str2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    asd
            cout
        << dp[str1.size()][str2.size()] << endl;

    return 0;
}
