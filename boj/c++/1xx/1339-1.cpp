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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int answer = 0;
    cin >> n;
    vector<string> v(n);
    vector<char> letters;

    for (int i = 0; i < n; i++) {
        cin >> v[i];

        for (char s : v[i]) {
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

    do {
        int sum = 0;

        for (int i = 0; i < m; i++) {
            alpha[letters[i]] = d[i];
        }

        for (int i = 0; i < v.size(); i++) {
            int kk = 0;
            for (int j = 0; j < v[i].size(); j++) {
                kk = kk * 10 + alpha[v[i][j]];
            }
            sum += kk;
        }
        answer = max(answer, sum);
    } while (next_permutation(d.begin(), d.end()));

    cout << answer << endl;
    return 0;
}
