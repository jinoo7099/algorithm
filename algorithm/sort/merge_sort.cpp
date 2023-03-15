#include <bits/stdc++.h>

using namespace std;

// O(nlogn)
// 1. 길이가 n, m인 정렬된 리스트
//    -> 주어진 리스트를 2개로 나누다.
// 2. 정렬된 두 리스트를 합친다.

// 맨 앞부터 비교해나간다.
// -9 1 6 8 12
// -7 7 13 15

// Stable Sort
// 38 21 21 21을 정렬할 때 순서가 유지 되면 Stable Sort이다.
// 앞 리스트, 뒤 리스트 우선순위가 같을때 앞리스트를 앞으로 보내줘야함

int n = 5;
int arr[1000001] = {5, 4, 3, 2, 1};
int tmp[1000001];

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

    for (int i = st; i < en; i++) {
        arr[i] = tmp[i];
    }
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

    merge_sort(0, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
