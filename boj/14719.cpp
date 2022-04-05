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

int h, w;
int arr[502];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;

    for (int i = 0; i < w; i++) {
        cin >> arr[i];
    }
    if (w <= 2) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i < w - 1; i++) {
        int cur = arr[i];

        int pivot = min(*max_element(arr, arr + i), *max_element(arr + i + 1, arr + w));
        if (pivot < cur) continue;
        ans += pivot - cur;
    }

    cout << ans << endl;

    return 0;
}
