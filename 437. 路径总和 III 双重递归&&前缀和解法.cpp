给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    void dfs(TreeNode* root, int sum)
    {
        if(root == nullptr)
            return;
        if(root->val == sum)
            ++cnt;
        dfs(root->left, sum - root->val);
        dfs(root->right, sum -  root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;
        dfs(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return cnt;
    }
};


class Solution {
public:
    unordered_map<int, int> count;
    int pathSum(TreeNode* root, int sum) {
        count[0] = 1;
        return helper(root, sum, 0);
    }
    int helper(TreeNode* root, int sum, int prefix_sum) {
        if (!root) return 0;
        int res = 0;
        prefix_sum += root->val;
        res += count[prefix_sum - sum];
        count[prefix_sum]++;
        res += helper(root->left, sum, prefix_sum) + helper(root->right, sum, prefix_sum);
        count[prefix_sum]--;
        return res;
    }
};