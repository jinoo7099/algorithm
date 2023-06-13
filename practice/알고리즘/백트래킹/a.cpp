#include <iostream>

using namespace std;
// 순열

int n;
int arr[4] = {1, 2, 3, 4};
int res[4];
int vis[4];

void permutation(int cur) {
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            cout << res[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        vis[i] = true;
        res[cur] = arr[i];
        permutation(cur + 1);

        vis[i] = false;
    }
}

void combination(int cur, int st, int k) {
    if (cur == k) {
        for (int i = 0; i < k; i++) {
            cout << res[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = st; i < n; i++) {
        if (vis[i]) continue;

        vis[i] = true;
        res[cur] = arr[i];
        combination(cur + 1, i + 1, k);

        vis[i] = false;
    }
}
int main() {
    n = 4;

    permutation(0);
    cout << "####" << endl;
    combination(0, 0, 3);
    return 0;
}