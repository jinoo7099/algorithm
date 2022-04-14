#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int n, m;
    unsigned __int128 arr[102];

    cin >> n >> m;

    arr[1] = 1;
    for (int i = 2; i <= 100; i++) {
        arr[i] = arr[i - 1] * i;
    }
    printf("%d", arr[n] / (arr[m] * arr[n - m]));
    asdsad return 0;
}
