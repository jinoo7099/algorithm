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

struct fire {
    int r;
    int c;
    int m;
    int s;
    int d;

    fire(int r, int c, int m, int s, int d) {
        this->r = r;
        this->c = c;
        this->m = m;
        this->s = s;
        this->d = d;
    }
};

vector<fire> v;

void move() {
    vector<fire> t;

    for (auto a : v) {
        int nx = (a.r + dx[a.d] * a.s + n * 100000) % n;
        int ny = (a.c + dy[a.d] * a.s + n * 100000) % n;

        t.push_back(fire(nx, ny, a.m, a.s, a.d));
    }

    v = t;
}

void merge() {
    map<pair<int, int>, vector<fire>> mp;
    vector<fire> t;

    for (auto a : v) {
        mp[{a.r, a.c}].push_back(fire(a.r, a.c, a.m, a.s, a.d));
    }

    for (auto a : mp) {
        if (a.se.size() >= 2) {
            int mm = 0;
            int ss = 0;

            for (auto b : a.se) {
                mm += b.m;
                ss += b.s;
            }

            mm /= 5;
            ss /= a.se.size();

            if (mm == 0) {
                continue;
            }

            bool flag1 = false;  // 모두 홀수
            bool flag2 = false;  // 모두 짝수

            for (auto b : a.se) {
                if (b.d % 2 == 0) {
                    flag2 = true;
                } else {
                    flag1 = true;
                }
            }

            if (flag1 == false || flag2 == false) {
                // 0 2 4 6
                for (int i = 0; i < 8; i += 2) {
                    t.push_back(fire(a.fi.fi, a.fi.se, mm, ss, i));
                }
            } else {
                for (int i = 1; i < 8; i += 2) {
                    t.push_back(fire(a.fi.fi, a.fi.se, mm, ss, i));
                }
            }

        } else {
            t.push_back(a.se[0]);
        }
    }
    v = t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int rr, cc, mm, ss, dd;
        cin >> rr >> cc >> mm >> ss >> dd;
        v.push_back(fire(rr, cc, mm, ss, dd));
    }

    while (k--) {
        move();
        merge();
    }

    int ans = 0;
    for (auto a : v) {
        ans += a.m;
    }
    cout << ans << endl;

    return 0;
}
