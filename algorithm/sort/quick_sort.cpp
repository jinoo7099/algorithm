#include <bits/stdc++.h>

using namespace std;

// O(nlogn)
// 각 처리마다 O(N) 필요, 재귀 트리가 O(logN) ~ O(N)

// 최악의 경우
// 1 2 3 4 5 6 7 8
// O(N^2)

// STL을 못쓰고 정렬을 직접 구현할 때는 무조건 merge sort같은 O(nlogn)이 보장되는 정렬 쓰기
// 퀵소트의 장점은 추가적인 공간이 필요하지 않다는 것
// -> In-place Sort
// 배열안에 자리바꿈 만으로 처리가 되기 때문에 cache hit rate 높아서 속도가 빠름

int n = 5;
int arr[1000001] = {5, 4, 3, 2, 1};

void quick_sort(int st, int en) {
    if (en <= st + 1) return;
    int pivot = arr[st];
    int l = st + 1;
    int r = en - 1;

    while (1) {
        while (l <= r and arr[l] <= pivot) l++;
        while (l <= r and arr[r] >= pivot) r--;
        if (l > r) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);

    quick_sort(st, r);
    quick_sort(r + 1, en);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    quick_sort(0, 5);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
