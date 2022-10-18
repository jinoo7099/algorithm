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

int n, white, blue;
int arr[200][200];

bool check(int cur, int row, int col) {
    for (int i = row; i < row + cur; i++) {
        for (int j = col; j < col + cur; j++) {
            if (arr[i][j] != arr[row][col]) {
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int row, int col) {
    if (check(x, row, col)) {
        if (arr[row][col])
            blue++;
        else
            white++;
        return;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            solve(x / 2, x / 2 * i + row, x / 2 * j + col);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    solve(n, 0, 0);

    cout << white << endl
         << blue << endl;
    return 0;
}
