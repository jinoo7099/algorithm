#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, k, ans;
string s[50];
vector<int> res(26);

void solve(int cur, int x) {
    if (cur == k) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int check = true;
            for (int j = 0; j < s[i].size(); j++) {
                if (!res[s[i][j] - 'a']) {
                    check = false;
                    break;
                }
            }
            if (check)
                cnt++;
        }
        ans = max(ans, cnt);

        return;
    }

    for (int i = x; i < 26; i++) {
        if (res[i]) continue;

        res[i] = 1;
        solve(cur + 1, i + 1);
        res[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    if (k < 5) {
        cout << 0 << endl;
        return 0;
    } else if (k == 26) {
        cout << n << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i] = s[i].substr(4);
        for (int j = 0; j < 4; ++j) {
            s[i].pop_back();
        }
    }
    res['a' - 'a'] = res['c' - 'a'] = res['n' - 'a'] = res['t' - 'a'] = res['i' - 'a'] = 1;
    k -= 5;

    solve(0, 0);

    cout << ans << endl;
    return 0;
}

/*
    백트래킹으로 풀었을떄 2^21 * 50 * 26 으로 시간 초과

    고집해서 백트래킹으로 풀다가 못풀고 dfs 완전 탐색으로 품

    둘이 똑같긴 한데 백트래킹은 선택 or 비 선택으로 풀어서 깊은 이진 트리

    dfs 완전 탐색은 옆으로 넒은 트리

    둘다 dfs 완전 탐색이지만 잘 구분해서 사용하기..!
*/