#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;
int dist[30][30];
vector<int> arr[444];
int point[5] = {0, 1, 10, 100, 1000};

struct Student {
    int r;
    int c;
    int like;
    int space;

    Student(int r, int c, int l, int s) {
        this->r = r;
        this->c = c;
        this->like = l;
        this->space = s;
    }
};

bool cmp(const Student& s1, const Student& s2) {
    if (s1.like || s2.like) {
        if (s1.like != s2.like) return s1.like > s2.like;
        if (s1.space != s2.space) return s1.space > s2.space;
        if (s1.r != s2.r) return s1.r < s2.r;
        return s1.c < s2.c;
    } else {
        if (s1.space != s2.space) return s1.space > s2.space;
        if (s1.r != s2.r) return s1.r < s2.r;
        return s1.c < s2.c;
    }
}

void solve(int p) {
    vector<Student> s;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j]) continue;

            int like = 0, space = 0;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

                if (dist[nx][ny] == 0)
                    space++;

                for (int l = 0; l < 4; l++) {
                    if (dist[nx][ny] == arr[p][l])
                        like++;
                }
            }

            s.push_back(Student(i, j, like, space));
        }
    }
    sort(s.begin(), s.end(), cmp);
    Student stu = s[0];
    dist[stu.r][stu.c] = p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> order;

    for (int i = 0; i < n * n; i++) {
        int m;
        cin >> m;
        order.push_back(m);
        for (int j = 0; j < 4; j++) {
            int a;
            cin >> a;
            arr[m].push_back(a);
        }
    }

    for (int i = 0; i < n * n; i++) {
        solve(order[i]);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int like = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

                for (int l = 0; l < 4; l++) {
                    if (dist[nx][ny] == arr[dist[i][j]][l])
                        like++;
                }
            }
            ans += point[like];
        }
    }
    cout << ans << endl;
    return 0;
}
