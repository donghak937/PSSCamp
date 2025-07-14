class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        int mid = nums.size() / 2;
        TreeNode* a = new TreeNode(nums[mid]);
        vector<int> left, right;
        for(int i = 0; i < mid; i++){
            left.push_back(nums[i]);
        }
        for(int i = mid + 1; i < nums.size(); i++){
            right.push_back(nums[i]);
        }
        a->left = sortedArrayToBST(left);
        a->right = sortedArrayToBST(right);
        return a;
    }
};