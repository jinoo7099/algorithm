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

vector<int> arr;
vector<int> cnt;
vector<int> res;
vector<pair<int, int>> q;
int n, k;

bool cmp(pair<int, int> &q1, pair<int, int> &q2) {
    if (q1.first / k != q2.first / k) return q1.first / k < q2.first / k;
    return q1.second < q2.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    k = sqrt(n);
    int maxx = -1;
    arr = vector<int>(n + 1);
    cnt = vector<int>(2 * 1e5 + 1, -1);
    res = vector<int>(2 * 1e5 + 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (cnt[arr[i]] + 1 != i) {
            q.push_back({cnt[arr[i]] + 1, i - 1});
        }
        cnt[arr[i]] = i;
    }

    sort(q.begin(), q.end(), cmp);

    ll t_cnt = 0;
    int st = q[0].first, en = q[0].second;
    for (int i = st; i <= en; i++) {
        if (res[arr[i]] == 0) t_cnt++;
        res[arr[i]]++;
    }

    ll ans = t_cnt;

    for (int i = 1; i < q.size(); i++) {
        while (st < q[i].first) {
            if (res[arr[st]] == 1) t_cnt--;
            res[arr[st]]--;
            st++;
        }
        while (st > q[i].first) {
            --st;
            if (res[arr[st]] == 0) t_cnt++;
            res[arr[st]]++;
        }
        while (en < q[i].second) {
            ++en;
            if (res[arr[en]] == 0) t_cnt++;
            res[arr[en]]++;
        }
        while (en > q[i].second) {
            if (res[arr[en]] == 1) t_cnt--;
            res[arr[en]]--;
            en--;
        }
        ans += t_cnt;
    }
    cout << ans << endl;
    return 0;
}
