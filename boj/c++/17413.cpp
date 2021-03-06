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

void printStack(stack<char>& st) {
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

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
            printStack(st);
            flag = true;
            cout << c;
        } else if (c == '>') {
            flag = false;
            cout << c;
        } else if (flag) {
            cout << c;
        } else if (c == ' ') {
            printStack(st);
            cout << c;
        } else {
            st.push(c);
        }
    }
    printStack(st);

    return 0;
}
