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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d, n;
    cin >> a >> b >> c >> d;

    int k = lcm(b, d);
    // 3 10
    // 3 5
    // 9 10
    int top, down;
    top = k / b * a + k / d * c;
    down = k;

    n = min(top, down);
    for (int i = 2; i < n; i++) {
        while (top % i == 0 and down % i == 0) {
            top /= i;
            down /= i;
        }
    }

    cout << top << ' ' << down << endl;
    return 0;
}
