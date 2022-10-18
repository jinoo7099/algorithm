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
    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty())
                cout << 0 << endl;
            else {
                cout << pq.top().second << endl;
                pq.pop();
            }
        } else {
            pq.push({abs(x), x});
        }
    }
    return 0;
}
