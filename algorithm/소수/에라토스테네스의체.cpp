#include <bits/stdc++.h>

using namespace std;

bool prime[100002];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    fill(prime, prime + 100002, true);

    prime[1] = false;
    for (int i = 2; i * i < 100002; i++) {
        if (!prime[i]) continue;

        for (int j = i + i; j <= 100002; j += i) {
            prime[j] = false;
        }
    }

    return 0;
}