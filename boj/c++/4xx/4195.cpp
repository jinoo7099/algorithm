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
unordered_map<string, string> parent;
unordered_map<string, int> parent_cnt;

string getParent(string x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(string a, string b) {
    a = getParent(a);
    b = getParent(b);

    if (a < b) {
        parent[b] = a;
        parent_cnt[a] += parent_cnt[b];
    } else {
        parent[a] = b;
        parent_cnt[b] += parent_cnt[a];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, f;
    cin >> t;
    while (t--) {
        parent.clear();
        parent_cnt.clear();
        cin >> f;
        while (f--) {
            string a, b;
            cin >> a >> b;
            if (parent_cnt.find(a) == parent_cnt.end()) {
                parent_cnt[a] = 1;
                parent[a] = a;
            }
            if (parent_cnt.find(b) == parent_cnt.end()) {
                parent_cnt[b] = 1;
                parent[b] = b;
            }

            unionParent(a, b);
            cout << parent_cnt[parent[a]] << endl;
        }
    }

    return 0;
}
