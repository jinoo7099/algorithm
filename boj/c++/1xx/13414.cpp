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

    int k, l;
    cin >> k >> l;

    unordered_map<string, int> signup;
    for (int i = 0; i < l; i++) {
        string student_num;
        cin >> student_num;

        if (signup.find(student_num) != signup.end()) {
            signup.erase(student_num);
            signup[student_num] = i;
        } else {
            signup[student_num] = i;
        }
    }

    vector<pair<string, int>> slist(signup.begin(), signup.end());
    sort(slist.begin(), slist.end(), [](auto& a, auto& b) { return a.se < b.se; });

    int en = min(k, (int)slist.size());

    for (int i = 0; i < en; i++) {
        cout << slist[i].fi << endl;
    }
    return 0;
}
