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

/*
    합성수 N에서 1을 제외한 가장 작은 약수는 (루트 N) 이하이다.

    -> 2부터 (루트 N) 까지의 수로 나누어지지 않으면 소수다.
*/