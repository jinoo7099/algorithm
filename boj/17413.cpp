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

    string str;
    getline(cin, str);
    stack<char> st;
    bool flag = false;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];

        if (c == '<') {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            flag = true;
        }

        if (flag) {
            cout << c;
        } else {
            if (c == ' ') {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            } else
                st.push(c);
        }
        if (c == '>') {
            flag = false;
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}
