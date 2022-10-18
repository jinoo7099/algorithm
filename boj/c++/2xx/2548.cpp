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

int arr[20002];
int res[20002];

int main() {
    int n, maxx = -1, minx = 1e9;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        maxx = max(maxx, arr[i]);
    }

    for (int i = 1; i <= maxx; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += abs(arr[j] - i);
        }
        res[i] = sum;
        minx = min(sum, minx);
    }

    for (int i = 1; i <= maxx; i++) {
        if (minx == res[i]) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}
