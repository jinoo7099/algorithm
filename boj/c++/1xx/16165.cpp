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

    int n, m;

    cin >> n >> m;

    unordered_map<string, vector<string>> groups;
    unordered_map<string, string> girls;

    for (int i = 0; i < n; i++) {
        string group;
        cin >> group;

        int group_num;
        cin >> group_num;

        vector<string> tmp;
        for (int j = 0; j < group_num; j++) {
            string girl;
            cin >> girl;
            tmp.push_back(girl);
            girls[girl] = group;
        }

        groups[group] = tmp;
    }

    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        int k;
        cin >> k;

        if (k == 0) {
            // 팀의 이름 -> 해당 팀에 속한 멤버의 이름을 사전순
            vector<string> a = groups[str];
            sort(a.begin(), a.end());

            for (auto s : a) {
                cout << s << endl;
            }
        } else {
            // 해당 멤버가 속한 팀의 이름
            cout << girls[str] << endl;
        }
    }

    return 0;
}
