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

int get_sum(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] > '0' && s[i] <= '9') {
            sum += s[i] - '0';
        }
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), [&](string a, string b) {
        if (a.size() != b.size()) return a.size() < b.size();
        int asum = get_sum(a);
        int bsum = get_sum(b);
        if (asum != bsum) return asum < bsum;

        return a < b;
    });

    for (int i = 0; i < n; i++)
        cout << v[i] << endl;
    return 0;
}
