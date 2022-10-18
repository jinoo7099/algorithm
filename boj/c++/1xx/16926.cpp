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
int arr[302][302];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    while (r--) {
        int x1 = 0, y1 = 0;
        int x2 = 0, y2 = m - 1;
        int x3 = n - 1, y3 = m - 1;
        int x4 = n - 1, y4 = 0;

        while (x1 < x4 && y1 < y2) {
            int temp = arr[x1][y1];
            for (int i = y1; i < y2; i++)
                arr[x1][i] = arr[x1][i + 1];
            for (int i = x2; i < x3; i++)
                arr[i][y2] = arr[i + 1][y2];
            for (int i = y3; i > y4; i--)
                arr[x3][i] = arr[x3][i - 1];
            for (int i = x4; i > x1; i--)
                arr[i][y4] = arr[i - 1][y4];
            arr[x1 + 1][y1] = temp;
            x1 += 1;
            y1 += 1;
            x2 += 1;
            y2 -= 1;
            x3 -= 1;
            y3 -= 1;
            x4 -= 1;
            y4 += 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
