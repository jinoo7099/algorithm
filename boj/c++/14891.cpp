/*
    톱니바퀴 - 시뮬레이션
    참고 - https://rile1036.tistory.com/92
    반복문 대신 재귀로 갈수도
*/

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

string str[4];
int k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; i++) {
        cin >> str[i];
    }

    cin >> k;

    // 6 - 2
    while (k--) {
        int a, b;
        // string tmp[4];
        int check[4] = {
            0,
        };
        cin >> a >> b;
        int d1, d2;
        a -= 1;
        d1 = d2 = b;
        for (int j = a; j > 0; j--) {
            if (str[j][6] == str[j - 1][2]) {
                check[j] = d1;
                break;
            } else {
                check[j] = d1;
                check[j - 1] = -d1;
                d1 = -d1;
            }
        }
        for (int j = a; j < 3; j++) {
            if (str[j][2] == str[j + 1][6]) {
                check[j] = d2;
                break;
            } else {
                check[j] = d2;
                check[j + 1] = -d2;
                d2 = -d2;
            }
        }

        for (int i = 0; i < 4; i++) {
            if (check[i] == 1) {
                str[i].insert(str[i].begin(), str[i].back());
                str[i].pop_back();
            } else if (check[i] == -1) {
                str[i].push_back(str[i].front());
                str[i].erase(str[i].begin());
            }
        }
    }
    // 1 S , 0 N
    int sum = 0;
    sum += (str[0][0] == '1') ? 1 : 0;
    sum += (str[1][0] == '1') ? 2 : 0;
    sum += (str[2][0] == '1') ? 4 : 0;
    sum += (str[3][0] == '1') ? 8 : 0;
    cout << sum << endl;

    return 0;
}
