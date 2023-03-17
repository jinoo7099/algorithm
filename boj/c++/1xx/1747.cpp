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

    vector<bool> primes(10000002, true);
    primes[1] = false;

    for (int i = 2; i * i <= 10000002; i++) {
        if (!primes[i]) continue;
        for (int j = i * i; j <= 10000002; j += i) {
            primes[j] = false;
        }
    }

    for (int i = n; i <= 10000002; i++) {
        if (primes[i]) {
            string s = to_string(i);
            bool flag = true;
            int size = s.size();

            for (int j = 0; j < size; j++) {
                if (s[j] != s[size - 1 - j]) {
                    flag = false;
                }
            }

            if (flag) {
                cout << s << endl;
                return 0;
            }
        }
    }

    return 0;
}
