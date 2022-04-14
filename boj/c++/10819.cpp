#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int arr[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int ans = -1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    do {
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += abs(arr[i] - arr[i + 1]);
        }
        ans = max(sum, ans);
    } while (next_permutation(arr, arr + n));
    cout << ans << endl;
    return 0;
}
