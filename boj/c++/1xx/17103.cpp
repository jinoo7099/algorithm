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

    int n;
    cin >> n;

    vector<bool> primes(1000001, true);
    primes[1] = false;

    for (int i = 2; i * i <= 1000001; i++) {
        if (!primes[i]) continue;
        for (int j = i * i; j <= 1000001; j += i) {
            primes[j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        int ans = 0;

        for (int j = 2; j <= num / 2; j++) {
            if (primes[j] and primes[num - j]) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
