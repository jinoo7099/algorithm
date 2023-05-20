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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unsigned int cupNoodles = 0;
    priority_queue<unsigned int> cn_candidate;
    vector<vector<unsigned int>> cn_by_deadline(200'002);

    for (int i = 0; i < n; i++) {
        int dl, cn;
        cin >> dl >> cn;
        cn_by_deadline[dl].push_back(cn);
    }

    for (int curr = 200'001; curr != 0; curr--) {
        for (int noodle : cn_by_deadline[curr])
            cn_candidate.push(noodle);

        if (cn_candidate.empty()) continue;

        cupNoodles += cn_candidate.top();
        cn_candidate.pop();
    }

    cout << cupNoodles << endl;

    return 0;
}
