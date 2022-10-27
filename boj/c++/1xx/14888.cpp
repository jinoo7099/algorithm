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

int calc(vector<int> a, vector<int> d) {
    for (int i = 0; i < a.size() - 1; i++) {
        int o = d[i];

        if (o == 0) {
            a[i + 1] = a[i] + a[i + 1];
        } else if (o == 1) {
            a[i + 1] = a[i] - a[i + 1];
        } else if (o == 2) {
            a[i + 1] = a[i] * a[i + 1];
        } else {
            a[i + 1] = a[i] / a[i + 1];
        }
    }

    return a[a.size() - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> d;
    for (int i = 0; i < 4; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            d.push_back(i);
        }
    }
    sort(d.begin(), d.end());

    int minx = 2e9;
    int maxx = -2e9;

    do {
        int now = calc(a, d);
        minx = min(minx, now);
        maxx = max(maxx, now);
    } while (next_permutation(d.begin(), d.end()));

    cout << maxx << endl
         << minx << endl;

    return 0;
}
