#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int arr[1002];
int d[1002];
int pre[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        d[i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                if (d[i] < d[j] + 1) {
                    d[i] = max(d[i], d[j] + 1);
                    pre[i] = j;
                }
            }
        }
    }

    int k = max_element(d, d + n + 1) - d;

    stack<int> s;

    while (k) {
        s.push(arr[k]);
        k = pre[k];
    }

    cout << s.size() << endl;
    while (s.size()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}
