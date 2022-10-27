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

char alpha[256];
int calc(vector<string>& a, vector<char>& letters, vector<int>& d) {
    int m = letters.size();
    int sum = 0;

    for (int i = 0; i < m; i++) {
        alpha[letters[i]] = d[i];
    }

    for (string s : a) {
        int now = 0;
        for (char x : s) {
            now = now * 10 + alpha[x];
        }
        sum += now;
    }

    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> a(n);
    vector<char> letters;
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        for (char s : a[i]) {
            letters.push_back(s);
        }
    }

    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());

    vector<int> d;
    int m = letters.size();

    for (int i = 9; i > 9 - m; i--) {
        d.push_back(i);
    }

    sort(d.begin(), d.end());

    int ans = 0;
    do {
        int r = calc(a, letters, d);
        ans = max(ans, r);
    } while (next_permutation(d.begin(), d.end()));

    cout << ans << endl;
    return 0;
}
