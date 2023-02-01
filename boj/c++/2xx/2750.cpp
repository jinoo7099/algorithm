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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, idx;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        int idx = 0;
        for (int j = i; j >= 0; j--) {
            if (v[idx] < v[j]) idx = j;
        }
        swap(v[i], v[idx]);
    }

    for (int i = 0; i < n; i++)
        cout << v[i] << endl;

    return 0;
}
