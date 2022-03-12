#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    int vis[1002];
    int len = 0;
    vector<vector<Node*>> v;

    Node* connect(Node* root) {
        if (!root) return NULL;

        solve(root, 0);

        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                cout << v[i][j]->val << ' ';
                if (j == v[i].size() - 1) {
                    v[i][j]->next = NULL;
                } else {
                    v[i][j]->next = v[i][j + 1];
                }
            }
            cout << '\n';
        }

        return root;
    }

    void solve(Node* root, int cur) {
        len = max(len, cur);
        if (!vis[cur]) {
            v.push_back(vector<Node*>());
            vis[cur] = 1;
        }

        if (root->left) {
            v[cur].push_back(root->left);
            solve(root->left, cur + 1);
        }

        if (root->right) {
            v[cur].push_back(root->right);
            solve(root->right, cur + 1);
        }
    }
};