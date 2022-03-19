#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int arr[1002];
int res[1002];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        q.push(i);
    }

    int t = 1;

    while (!q.empty()) {
        int cur = q.front();
        res[cur] = t++;
        if (arr[cur] > 1) {
            q.push(cur);
            arr[cur]--;
        }
        q.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    return 0;
}
