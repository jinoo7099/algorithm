#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;
vector<int> arr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int k;

    for (int i = 0; i < n; i++) {
        cin >> k;
        arr.push_back(k);
    }

    sort(arr.begin(), arr.end());

    int low, high;
    low = 0;
    high = arr.size() - 1;

    int res = 1e10;
    int a, b;
    while (low < high) {
        int sum = arr[low] + arr[high];

        if (res >= abs(sum)) {
            res = abs(sum);
            a = arr[low];
            b = arr[high];
        }

        if (sum > 0) {
            high--;
        } else {
            low++;
        }
    }

    cout << a << ' ' << b << endl;

    return 0;
}
