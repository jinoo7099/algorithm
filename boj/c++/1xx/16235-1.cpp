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

int t_dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int t_dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m, k;
int add_food[12][12];
vector<int> trees[12][12];
int cur_food[12][12];
int dead_tree_age;

void spring() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dead_tree_age = 0;
            sort(trees[i][j].begin(), trees[i][j].end());

            int food = cur_food[i][j];
            vector<int> new_trees;

            for (int t = 0; t < trees[i][j].size(); t++) {
                int age = trees[i][j][t];
                if (food - age < 0) {
                    dead_tree_age += age / 2;
                    continue;
                }

                food -= age;
                new_trees.push_back(age + 1);
            }

            cur_food[i][j] = food;
            trees[i][j] = new_trees;

            // summer
            cur_food[i][j] += dead_tree_age;
        }
    }
}

void spread(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + t_dx[i];
        int ny = y + t_dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

        trees[nx][ny].push_back(1);
    }
}

void fall() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int t = 0; t < trees[i][j].size(); t++) {
                if (trees[i][j][t] % 5 == 0) {
                    spread(i, j);
                }
            }
        }
    }
}

void winter() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cur_food[i][j] += add_food[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> add_food[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cur_food[i][j] = 5;

    for (int i = 0; i < k; i++) {
        spring();
        // summer
        fall();
        winter();
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += trees[i][j].size();
        }
    }
    cout << ans << endl;

    return 0;
}
