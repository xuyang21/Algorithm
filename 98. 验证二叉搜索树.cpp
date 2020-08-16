给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 每个节点都有上限和下限， 每次递归把上下限当作参数
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return _isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool _isValidBST(TreeNode* root, long long low, long long high)
    {
        if(root == NULL)
            return true;
        if(root->val > low  && root->val < high)
            return _isValidBST(root->left, low, root->val) && _isValidBST(root->right, root->val, high);
        return false;
    }
};

// 更巧妙的方法
class Solution {
    double last = -Double.MAX_VALUE;
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (isValidBST(root.left)) {
            if (last < root.val) {
                last = root.val;
                return isValidBST(root.right);
            }
        }
        return false;
    }
}
