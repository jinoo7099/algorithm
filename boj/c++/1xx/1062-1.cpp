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

int n, k;
int alpha[26];
int ans;

void go(int cur, vector<string> words, int x) {
    if (cur == k) {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int flag = true;
            for (int j = 0; j < words[i].size(); j++) {
                if (alpha[words[i][j] - 'a'] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        }

        ans = max(ans, cnt);
        return;
    }

    for (int i = x; i < 26; i++) {
        if (alpha[i]) continue;
        alpha[i] = 1;
        go(cur + 1, words, i + 1);
        alpha[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    // a n t i c
    if (k < 5) {
        cout << 0 << endl;
        return 0;
    } else if (k == 26) {
        cout << n << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        words[i] = words[i].substr(4);

        for (int j = 0; j < 4; j++) {
            words[i].pop_back();
        }
    }

    alpha['a' - 'a'] = alpha['c' - 'a'] = alpha['n' - 'a'] = alpha['t' - 'a'] = alpha['i' - 'a'] = 1;
    k -= 5;

    go(0, words, 0);

    cout << ans << endl;
    return 0;
}
