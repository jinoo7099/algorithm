#include <bits/stdc++.h>

using namespace std;

// 해당 순서에 원소를 넣을 위치는 이미 정해져 있고,
// 어떤 원소를 넣을지 선택하는 알고리즘

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 5;
    int arr[] = {2, 4, 3, 1, 5};

    for (int i = 0; i < N - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        swap(arr[i], arr[min_index]);
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
