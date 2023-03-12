#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;
int arr[52][10];
int roo[5];
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> order;
    for (int i = 1; i <= 9; i++) order.push_back(i);

    do {
        if (order[3] == 1) {
            int hitter_num = 0;  // 시작 타자
            int score = 0;
            // for (auto a : order) {
            //     cout << a << ' ';
            // }
            // cout << endl;

            for (int ining = 1; ining <= n; ining++) {
                memset(roo, 0, sizeof(roo));
                int out_count = 0;

                while (1) {
                    if (out_count == 3) break;
                    int k = arr[ining][order[hitter_num]];  // 타자 행동
                    // cout << k << ' ';
                    if (k == 0) {
                        out_count++;
                    } else if (k == 1) {
                        if (roo[3] == 1) {
                            score++;
                            roo[3] = 0;
                        }
                        if (roo[2] == 1) {
                            roo[3] = 1;
                            roo[2] = 0;
                        }
                        if (roo[1] == 1) {
                            roo[2] = 1;
                            roo[1] = 0;
                        }
                        roo[1] = 1;
                    } else if (k == 2) {
                        if (roo[3] == 1) {
                            score++;
                            roo[3] = 0;
                        }
                        if (roo[2] == 1) {
                            score++;
                            roo[2] = 0;
                        }
                        if (roo[1] == 1) {
                            roo[3] = 1;
                            roo[1] = 0;
                        }
                        roo[2] = 1;
                    } else if (k == 3) {
                        for (int i = 1; i <= 3; i++) {
                            if (roo[i] == 1) {
                                score++;
                                roo[i] = 0;
                            }
                        }
                        roo[3] = 1;
                    } else if (k == 4) {
                        for (int i = 1; i <= 3; i++) {
                            if (roo[i] == 1) {
                                score++;
                                roo[i] = 0;
                            }
                        }
                        score++;
                    }
                    hitter_num++;

                    if (hitter_num >= 9)
                        hitter_num = 0;
                }
            }
            ans = max(ans, score);
        }

    } while (next_permutation(order.begin(), order.end()));

    cout << ans << endl;
    return 0;
}
