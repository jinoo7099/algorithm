#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int t;
ll arr[2][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    arr[0][0] = 1;
    arr[1][1] = 1;

    for (int i = 2; i <= 50; i++) {
        arr[0][i] = arr[0][i - 1] + arr[0][i - 2];
        arr[1][i] = arr[1][i - 1] + arr[1][i - 2];
    }

    while (t--) {
        int c;
        cin >> c;

        cout << arr[0][c] << ' ' << arr[1][c] << endl;
    }

    return 0;
}
