#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vis[10]={};
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        solve(nums, v, 0, res);
        return res;
    }
    
    void solve(vector<int>& nums, vector<int>& temp, int cur, vector<vector<int>>& res) {
        if(cur == nums.size()) {
            res.push_back(temp);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(vis[i]) continue;
            
            temp.push_back(nums[i]);
            vis[i]=1;
            solve(nums, temp, cur+1, res);
            vis[i]=0;
            temp.pop_back();
        }
    }
};