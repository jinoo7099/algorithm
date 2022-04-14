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

    int n, f;

    cin >> n >> f;

    int p = n % 100 - n % f;

    if (p < 0) p += f;

    while (p >= 0) {
        p -= f;
    }

    if (p + f < 10)
        cout << "0" << p + f << endl;
    else
        cout << p + f << endl;

    return 0;
}
