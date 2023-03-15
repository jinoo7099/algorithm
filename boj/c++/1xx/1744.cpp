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

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int zero = 0;
    vector<int> arr(n);
    vector<int> odds;
    vector<int> evens;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0) {
            zero++;
        } else if (arr[i] > 0) {
            evens.push_back(arr[i]);
        } else {
            odds.push_back(arr[i]);
        }
    }

    ll ans = 0;

    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());

    for (int i = evens.size() - 1; i >= 0; i--) {
        if (i - 1 >= 0) {
            ans += max(evens[i] * evens[i - 1], evens[i] + evens[i - 1]);
            i--;
        } else {
            ans += evens[i];
        }
    }
    if (zero > 0 and odds.size() % 2 == 1) {
        odds.pop_back();
    }

    for (int i = 0; i < odds.size(); i++) {
        if (i + 1 < odds.size()) {
            ans += max(odds[i] * odds[i + 1], odds[i] + odds[i + 1]);
            i++;
        } else {
            ans += odds[i];
        }
    }

    cout << ans << endl;

    return 0;
}
