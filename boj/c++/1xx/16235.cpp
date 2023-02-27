#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m, k;
vector<int> arr[12][12];
int water[12][12];      // 현재 양분
int add_water[12][12];  // 기계로 보충될 양분

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> add_water[i][j];
            water[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arr[x][y].push_back(z);
    }

    // 1
    while (k--) {
        int sum = 0;
        // spring
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j].size() == 0) continue;

                int remained_water = water[i][j];
                sort(arr[i][j].begin(), arr[i][j].end());

                int sum = 0;
                int cnt = 0;
                for (int ii = 0; ii < arr[i][j].size(); ii++) {
                    if (remained_water >= arr[i][j][ii]) {
                        remained_water -= arr[i][j][ii];
                        arr[i][j][ii] += 1;
                    } else {
                        sum += arr[i][j][ii] / 2;
                        cnt++;
                    }
                }
                water[i][j] = remained_water;

                // summer
                water[i][j] += sum;
                for (int ii = 0; ii < cnt; ii++) {
                    arr[i][j].pop_back();
                }
            }
        }

        // fall
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j].size() == 0) continue;

                for (int ii = 0; ii < arr[i][j].size(); ii++) {
                    if (arr[i][j][ii] % 5 == 0 and arr[i][j][ii] != 0) {
                        for (int d = 0; d < 8; d++) {
                            int nx = i + dx[d];
                            int ny = j + dy[d];

                            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                            arr[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
        // winter
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                water[i][j] += add_water[i][j];
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << arr[i][j][0] << '@' << water[i][j];
        //     }
        //     cout << endl;
        // }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += arr[i][j].size();
        }
    }
    cout << ans << endl;
    return 0;
}
