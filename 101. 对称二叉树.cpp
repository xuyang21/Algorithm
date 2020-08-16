给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

//递归形式多变，得仔细找到规律
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
    bool _isSymmetric(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        else if(root1 != NULL && root2 != NULL && root1->val == root2->val)
            return _isSymmetric(root1->right, root2->left) && _isSymmetric(root1->left, root2->right);
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        return _isSymmetric(root, root);
    }
};

//迭代解法，采用两个栈，依次比较左右子树相应位置的元素，时间和空间与递归一样
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        stack<TreeNode*> stack1, stack2;
        stack1.push(root->left);
        stack2.push(root->right);
        while(!stack1.empty() && !stack2.empty())
        {
            TreeNode* tmp1 = stack1.top();
            stack1.pop();
            TreeNode* tmp2 = stack2.top();
            stack2.pop();
            if(tmp1 == NULL && tmp2 == NULL)
                continue;
            else if(tmp1 != NULL && tmp2 != NULL && tmp1->val == tmp2->val)
            {
                stack1.push(tmp1->left);
                stack1.push(tmp1->right);
                stack2.push(tmp2->right);
                stack2.push(tmp2->left);
            }
            else
                return false;   
        }
        return true;
    }
};
