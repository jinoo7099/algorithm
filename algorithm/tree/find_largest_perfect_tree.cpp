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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct returnType {
    bool isPerfect;
    int height;
    TreeNode *rootTree;
};

returnType findPerfectBinaryTree(struct TreeNode *root) {
    returnType rt;

    if (root == NULL) {
        rt.isPerfect = true;
        rt.height = 0;
        rt.rootTree = NULL;
        return rt;
    }

    returnType lv = findPerfectBinaryTree(root->left);
    returnType rv = findPerfectBinaryTree(root->right);

    // if both left and right sub-trees ar perfect
    // and height is also same
    if (lv.isPerfect && rv.isPerfect && lv.height == rv.height) {
        rt.height = lv.height + 1;
        rt.isPerfect = true;
        rt.rootTree = root;
        return rt;
    }

    // Else this sub-tree cannot be a perfect binary tree
    // and simply return the biggest sized perfect sub-tree
    // found till now in the left or right sub-trees
    rt.isPerfect = false;
    rt.height = max(lv.height, rv.height);
    rt.rootTree = (lv.height > rv.height ? lv.rootTree : rv.rootTree);
    return rt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    struct returnType ans = findPerfectBinaryTree(root);
    // Height of the found sub-treeint h = ans.height;
    int h = ans.height;
    cout << "Height : " << h << endl;
    cout << "Size : " << pow(2, h) - 1 << endl;
    return 0;
}

/**
 *           1
 *        2     3
 *      4   5  6
 *
 */