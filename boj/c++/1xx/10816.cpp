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

int lower_idx(vector<int> a, int target) {
    int st, en, mid;
    st = 0;
    en = a.size();

    while (st < en) {
        mid = (st + en) / 2;
        if (a[mid] >= target)
            en = mid;
        else
            st = mid + 1;
    }

    return st;
}

int upper_idx(vector<int> a, int target) {
    int st, en, mid;
    st = 0;
    en = a.size();

    while (st < en) {
        mid = (st + en) / 2;
        if (a[mid] > target)
            en = mid;
        else
            st = mid + 1;
    }
    return st;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        cout << upper_bound(a.begin(), a.end(), t) - lower_bound(a.begin(), a.end(), t) << sp;
    }
    return 0;
}
