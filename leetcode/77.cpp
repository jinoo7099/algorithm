#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            v.push_back(i >= n - k ? 1 : 0);
        }
        do {
            vector<int> a;
            for (int i = 0; i < n; i++) {
                if (v[i]) {
                    a.push_back(i + 1);
                }
            }
            res.push_back(a);
        } while (next_permutation(v.begin(), v.end()));

        return res;
    }
};