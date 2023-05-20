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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        for (int i = 0; i < k; i++) {
            ll a;
            cin >> a;
            pq.push(a);
        }
        vector<ll> ans;
        while (pq.size() > 1) {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();

            pq.push(a + b);
            ans.push_back(a + b);
        }

        ll sum = 0;
        for (auto s : ans) {
            sum += s;
        }
        cout << sum << endl;
    }

    return 0;
}
