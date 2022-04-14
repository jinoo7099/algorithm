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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1 - i; j >= 1; j--) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
