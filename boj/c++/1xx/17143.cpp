#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct shark {
    int r;
    int c;
    int s;  // 속도
    int d;  // 방향
    int z;  // 크기
};

bool cmp(const shark& s1, const shark& s2) {
    if (s1.r != s2.r) return s1.r < s2.r;
    return s1.c < s2.c;
}

int r, c, m;
vector<shark> sharks;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 100 * 100  100
    cin >> r >> c >> m;

    for (int i = 0; i < m; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        sharks.push_back({r, c, s, d - 1, z});
    }

    int fish_man_idx = 0;
    int ans = 0;

    for (int i = 0; i < c; i++) {
        fish_man_idx++;

        vector<shark> catched_shark;
        vector<shark> remained_shark;
        for (auto s : sharks) {
            if (s.c == fish_man_idx) {
                catched_shark.push_back(s);
            } else {
                remained_shark.push_back(s);
            }
        }

        // r, c 순으로 정렬
        if (catched_shark.size() != 0) {
            sort(catched_shark.begin(), catched_shark.end(), cmp);

            // 상어 잡기
            ans += catched_shark.front().z;
        }

        // 상어 이동
        map<pair<int, int>, shark> sharks_after_move;

        for (int j = 1; j < catched_shark.size(); j++) {
            remained_shark.push_back(catched_shark[j]);
        }

        for (auto& shark : remained_shark) {
            int nx, ny;

            nx = shark.r;
            ny = shark.c;
            if (shark.d <= 1)
                shark.s %= (r - 1) * 2;
            else
                shark.s %= (c - 1) * 2;

            for (int j = 0; j < shark.s; j++) {
                nx += dx[shark.d];
                ny += dy[shark.d];

                if (nx == 0) {
                    nx = 2;
                    shark.d = 1;
                } else if (nx == r + 1) {
                    nx = r - 1;
                    shark.d = 0;
                }

                if (ny == 0) {
                    ny = 2;
                    shark.d = 2;
                } else if (ny == c + 1) {
                    ny = c - 1;
                    shark.d = 3;
                }
            }

            if (sharks_after_move.find({nx, ny}) == sharks_after_move.end()) {
                sharks_after_move[{nx, ny}] = {nx, ny, shark.s, shark.d, shark.z};
            } else {
                if (sharks_after_move[{nx, ny}].z < shark.z) {
                    sharks_after_move[{nx, ny}] = {nx, ny, shark.s, shark.d, shark.z};
                }
            }

            // sharks_after_move[nx][ny].push_back({nx, ny, shark.s, shark.d, shark.z});
        }

        vector<shark> tmp;
        // for (int ii = 1; ii <= r; ii++) {
        //     for (int jj = 1; jj <= c; jj++) {
        //         if (sharks_after_move[ii][jj].size() == 0) continue;
        //         sort(sharks_after_move[ii][jj].begin(), sharks_after_move[ii][jj].end(), [](const shark& s1, const shark& s2) {
        //             return s1.z < s2.z;
        //         });
        //         tmp.push_back(sharks_after_move[ii][jj].back());
        //     }
        // }
        for (auto shark : sharks_after_move) {
            tmp.push_back(shark.second);
        }

        sharks = tmp;
    }

    cout << ans << endl;

    return 0;
}

/*
https://www.acmicpc.net/source/56564308
*/