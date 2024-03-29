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

pair<int, int> arr[20];
int d[20];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // 일하기 or 일안하기
    for (int i = 1; i <= n; i++) {
        d[i] = max(d[i], d[i - 1]);

        if (i + arr[i].first <= n + 1) {
            d[i + arr[i].first] = max(d[i + arr[i].first], d[i] + arr[i].second);
        }
    }

    cout << max(d[n], d[n + 1]) << endl;

    return 0;
}
