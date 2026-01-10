/*
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return 0;

        int total = 0;
        if (root->val >= low && root->val <= high) total += root->val;

        total += rangeSumBST(root->right,low,high);
        total += rangeSumBST(root->left,low,high);

        return total;
    }
};*/