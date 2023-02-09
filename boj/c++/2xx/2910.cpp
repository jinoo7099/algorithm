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

    int n, c;
    cin >> n >> c;

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bool chk = false;

        for (auto& a : arr) {
            if (a.se == x) {
                chk = true;
                a.fi++;
                break;
            }
        }
        if (!chk) arr.push_back({1, x});
    }

    stable_sort(arr.begin(), arr.end(), [](pii a, pii b) {
        return a.fi > b.fi;
    });

    for (auto a : arr) {
        while (a.fi--) {
            cout << a.se << " ";
        }
    }

    return 0;
}
