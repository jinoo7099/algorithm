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

string wheel[5];
int k;

string rotateNxt(string s) {
    string tmp = "";

    tmp += s.back();
    tmp += s.substr(0, s.size() - 1);

    return tmp;
}

string rotatePrev(string s) {
    string tmp = "";

    tmp += s.substr(1);
    tmp += s.front();

    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 4; i++) {
        cin >> wheel[i];
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        int a, d;
        cin >> a >> d;

        int ch[5] = {
            0,
        };

        ch[a] = d;
        int nxt_d = d;
        for (int j = a - 1; j >= 1; j--) {
            if (wheel[j + 1][6] == wheel[j][2]) {
                break;
            }
            nxt_d = -nxt_d;
            ch[j] = nxt_d;
        }

        nxt_d = d;
        for (int j = a + 1; j <= 4; j++) {
            if (wheel[j - 1][2] == wheel[j][6]) {
                break;
            }
            nxt_d = -nxt_d;
            ch[j] = nxt_d;
        }
        for (int j = 1; j <= 4; j++) {
            if (ch[j] == 1) {
                wheel[j] = rotateNxt(wheel[j]);
            } else if (ch[j] == -1) {
                wheel[j] = rotatePrev(wheel[j]);
            }
        }
    }
    int ans = 0;
    if (wheel[1][0] == '1') {
        ans += 1;
    }
    if (wheel[2][0] == '1') {
        ans += 2;
    }
    if (wheel[3][0] == '1') {
        ans += 4;
    }
    if (wheel[4][0] == '1') {
        ans += 8;
    }

    cout << ans << endl;

    return 0;
}
