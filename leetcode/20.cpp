#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty() || (st.top() == '(' && s[i] != ')') || (st.top() == '[' && s[i] != ']') || (st.top() == '{' && s[i] != '}')) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};