#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;

    cin >> n;

    while (n--) {
        int a;
        cin >> a;

        if (a != 0) {
            pq.push(-a);
        } else {
            if (pq.empty()) {
                cout << 0 << endl;
            } else {
                cout << -pq.top() << endl;
                pq.pop();
            }
        }
    }
    return 0;
}
