#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

int tmp[1000001];
int arr[1000001];

void merge(int st, int en) {
    int mid = (st + en) / 2;

    int aidx = st;
    int bidx = mid;
    for (int i = st; i < en; i++) {
        if (aidx == mid) {
            tmp[i] = arr[bidx++];
        } else if (bidx == en) {
            tmp[i] = arr[aidx++];
        } else if (arr[aidx] <= arr[bidx]) {
            tmp[i] = arr[aidx++];
        } else {
            tmp[i] = arr[bidx++];
        }
    }

    for (int i = st; i < en; i++)
        arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
    if (en == st + 1) return;
    int mid = (st + en) / 2;

    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(0, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}
