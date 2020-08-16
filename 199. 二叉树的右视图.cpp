给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---


/* 层序遍历，记录每一层最右边的值 */
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)  return {};
        queue<TreeNode*> order;
        vector<int> res;
        order.push(root);
        while(!order.empty())
        {
            int size = order.size();
            TreeNode* tmp;
            for(int i = 0; i < size; ++i)
            {
                tmp = order.front();
                order.pop();
                if(tmp->left)    order.push(tmp->left);
                if(tmp->right)   order.push(tmp->right);
            }
            res.push_back(tmp->val);
        }
        return res;
    }
};