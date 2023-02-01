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

int n;
int t;
const int MXN = 2'000'000, HALF = MXN / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<bool> isnum(MXN + 2);

    for (int i = 0; i < n; i++) {
        cin >> t;
        isnum[t + HALF] = true;
    }

    while (n--) {
        cin >> t;
        isnum[t + HALF] = true;
    }

    for (int i = MXN; i >= 0; i--) {
        if (isnum[i]) cout << i - HALF << endl;
    }

    return 0;
}
