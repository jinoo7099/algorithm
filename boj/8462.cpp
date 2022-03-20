#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

struct unit {
    int left;
    int right;
    int idx;

    unit() {}

    unit(int l, int r, int i) {
        left = l;
        right = r;
        idx = i;
    }
};

int n, t, k;
ll sum;
int low, high;
int arr[100005];
ll cnt[1000005];
ll res[1000005];
vector<unit> v;

bool cmp(const unit &u1, const unit &u2) {
    if (u1.left / k != u2.left / k) return u1.left / k < u2.left / k;
    return u1.right < u2.right;
}

void solve() {
    low = 1, high = n;
    for (int i = 0; i < t; i++) {
        int st = v[i].left;
        int end = v[i].right;
        //
        while (st < low) {
            low--;

            sum -= (cnt[arr[low]] * cnt[arr[low]] * arr[low]);
            cnt[arr[low]]++;
            sum += (cnt[arr[low]] * cnt[arr[low]] * arr[low]);
        }

        while (st > low) {
            sum -= (cnt[arr[low]] * cnt[arr[low]] * arr[low]);
            cnt[arr[low]]--;
            sum += (cnt[arr[low]] * cnt[arr[low]] * arr[low]);

            low++;
        }

        //
        while (end > high) {
            high++;

            sum -= (cnt[arr[high]] * cnt[arr[high]] * arr[high]);
            cnt[arr[high]]++;
            sum += (cnt[arr[high]] * cnt[arr[high]] * arr[high]);
        }

        while (end < high) {
            sum -= (cnt[arr[high]] * cnt[arr[high]] * arr[high]);
            cnt[arr[high]]--;
            sum += (cnt[arr[high]] * cnt[arr[high]] * arr[high]);
            high--;
        }

        res[v[i].idx] = sum;
    }

    for (int i = 0; i < t; i++) {
        cout << res[i + 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;

    k = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum -= (cnt[arr[i]] * cnt[arr[i]] * arr[i]);
        cnt[arr[i]]++;
        sum += (cnt[arr[i]] * cnt[arr[i]] * arr[i]);
    }

    int a, b;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        v.push_back(unit(a, b, i + 1));
    }

    sort(v.begin(), v.end(), cmp);

    solve();

    return 0;
}
